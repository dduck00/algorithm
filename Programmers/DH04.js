function solution(weights) {
    var MOBILS = new Array();
    var answer = 0;
    var len = weights.length;
    weights.sort();

    for (var idx = 0; idx < len; idx++) {
        var weight = weights[idx];
        MOBILS.push({
            "value": weight,
            "count": 1
        });
    }

    while(true){
        var temp = [];
        temp.push(MOBILS[0]);
        for (var idx = 1; idx < MOBILS.length; idx++) {
            if (temp[temp.length - 1].value === MOBILS[idx].value) {
                temp[temp.length - 1] = {
                    "value": MOBILS[idx].value * 2,
                    "count": temp[temp.length - 1].count + MOBILS[idx].count
                }
                continue;
            }
            temp.push(MOBILS[idx]);
        }
        if(diff(MOBILS, temp)){
            break;
        }
        temp.sort(function (a, b){
            if(a.value !== b.value)
                return a.value < b.value ? -1 : 1;
            return a.count > b.count ? -1 : 1;
        });

        MOBILS = temp;
    }

    for(var idx = 0; idx < MOBILS.length; idx++){
        answer = answer < MOBILS[idx].count ? MOBILS[idx].count : answer;
    }

    return answer;
}


function diff(src, trg){
    if(src.length !== trg.length)
        return false;

    for(var idx = 0 ; idx < src.length; idx++){
        if(src[idx].value !== trg[idx].value || src[idx].count !== trg[idx].count)
            return false;
    }
    return true;
}
