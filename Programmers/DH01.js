function solution(arr){
    var answer = 0;
    while(true){
        if(arr.length === 1 && arr[0] === 1)
            break;
        var temp = [1];
        answer++;
        for(var idx = 1; idx < arr.length; idx++){
            if(arr[idx-1] === arr[idx]){
                temp[temp.length -1]++;
                continue;
            }
            temp.push(1);
        }
        arr = temp;
    }
    return answer;
}
