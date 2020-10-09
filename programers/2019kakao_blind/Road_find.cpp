#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class tree{
private:
    tree * left;
    tree * right;
    int name;
    int y;
public:
    tree() : left(NULL), right(NULL) {}
    tree(int _y, int _name) : left(NULL), right(NULL), y(_y), name(_name) {}
    void init(int _y, int _name) {
        y = _y; name = _name;
    }
        
    void insert(int _y, int _name){
        if(y > _y){
            if(left == NULL){
                left = new tree();
                left->init(_y, _name);
            }else
                left->insert(_y, _name);
            
        }
        else{
            if(right == NULL){
                right = new tree();
                right->init(_y, _name);
            }else
                right->insert(_y, _name);
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
    
    return answer;
}