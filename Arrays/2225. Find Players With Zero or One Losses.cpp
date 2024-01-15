function findWinners(matches: number[][]): number[][] {
    const mp:Map<number,number>=new Map();

    for(let match of matches){
        let losser:number=match[1];
        mp[losser]++;
    }

    const ans:number[][]=[[],[]];
    const zeroLose:number[]=[];
    const oneLose:number[]=[];

    for(let match of matches){
        let losser:number=match[1];
        let winner:number=match[0];

        if(!mp.has(winner)){
            zeroLose.push(winner);
            mp.set(winner,-1);
        }
        if(mp.has(losser) && mp.get(losser) === 1){
            oneLose.push(losser);
        }
    }

    ans[0]=zeroLose.sort((a,b)=>a-b);
    ans[1]=oneLose.sort((a,b)=>a-b);

    return ans;

};

