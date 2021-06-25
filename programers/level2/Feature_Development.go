func solution(progresses []int, speeds []int) []int {
    
    var max, count int = 0, 0;
    result := []int{};
    
    for idx, n := range progresses {
        var remainPeriod int = 100 - n;
        var completPeriod int = 0;
        
        if ( remainPeriod % speeds[idx] != 0 ) {
            completPeriod = (remainPeriod / speeds[idx]) + 1;
        } else {
            completPeriod = remainPeriod / speeds[idx];
        }
        
        if( max < completPeriod ){
            result = append(result, count);
            count = 1;
            max = completPeriod;
        } else {
            count++;
        }
    }

    result = append(result[:0], result[1:]...);
    result = append(result, count);
    return result
}