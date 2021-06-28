function solution(progresses, speeds) {
    let [count, max] = [0, 0];
    
    return (progresses.reduce((prev, curr, idx) => {
        const timeRemain = 100 - curr;
        const day = parseInt(timeRemain / speeds[idx]);
        const completDay = timeRemain % speeds[idx] ? day + 1 : day;
        
        if(max < completDay){
            prev.push(count);
            max = completDay;
            count = 1;
        } else {
            count++;
        }
        
        return prev;
    }, []).filter(count => count)).concat(count);
}