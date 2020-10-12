#include <string>
#include <vector>
#include <memory>
#include <algorithm>

using namespace std;

class tree{
private:
    unique_ptr<tree> left;
    unique_ptr<tree> right;
    int name;
    int x;
public:
    tree() {}
    tree(int _x, int _name) : x(_x), name(_name) {}

    void init(int _x, int _name) {
        x = _x;
        name = _name;
    }
        
    void insert(int _x, int _name){
        if(x > _x){
            if(left == NULL){
                left = make_unique<tree>();
                left->init(_x, _name);
            }else
                left->insert(_x, _name);
            
        }
        else{
            if(right == NULL){
                right = make_unique<tree>();
                right->init(_x, _name);
            }else
                right->insert(_x, _name);
        }
    }

    void preorder(vector<vector<int>>& answer){
        answer[0].emplace_back(name);
        if(left != NULL)
            left->preorder(answer);
        
        if(right != NULL)
            right->preorder(answer);
    }
    
    void postorder(vector<vector<int>>& answer){
        if(left != NULL)
            left->postorder(answer);
        
        if(right != NULL)
            right->postorder(answer);
        
        answer[1].emplace_back(name);
    }
/* delete
    void del_tree(){
        if(left != NULL)
            left->del_tree();
        if(right != NULL)
            right->del_tree();
        
        delete left;
        delete right; 
    } */
};

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer(2);
    int i = 1;
    for(auto& v : nodeinfo) //노드 번호 부여
        v.emplace_back(i++);
    
    sort(nodeinfo.begin(), nodeinfo.end(), [](auto a, auto b){
        if(a[1] > b[1]) return true;
        else return false;
    });

    tree * t = new tree(nodeinfo[0][0], nodeinfo[0][2]);
    
    for(size_t i = 1; i < nodeinfo.size(); i++)
        t->insert(nodeinfo[i][0], nodeinfo[i][2]);
    
    t->preorder(answer);
    t->postorder(answer);
    
    //t->del_tree();
    return answer;
}