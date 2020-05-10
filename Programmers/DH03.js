function solution(requs) {
    var USER_LIST = new Map();
    var answer = [];
    var len = requs.length;

    for (var idx = 0; idx < len; idx++) {
        var splitList = requs[idx].split(' ');
        var order = splitList[0];
        var user = splitList[1];
        var pay = splitList[2];

        switch (order) {
            case "DEPOSIT":
                if(USER_LIST.has(user) === false){
                    answer.push("404");
                    break;
                }
                USER_LIST.set(user, USER_LIST.get(user) + pay)
                answer.push("200");
                break;

            case "CREATE":
                if(USER_LIST.has(user)){
                    answer.push("404");
                    break;
                }
                USER_LIST.set(user, pay);
                answer.push("200");
                break;

            case "WITHDRAW":
                if(USER_LIST.has(user) === false){
                    answer.push("404");
                    break;
                }
                var nowMoney = USER_LIST.get(user);
                if(nowMoney < pay){
                    answer.push("403");
                    break;
                }
                USER_LIST.set(user, USER_LIST.get(user) - pay)
                answer.push("200");

                break;
        }
    }
    return answer;
}
