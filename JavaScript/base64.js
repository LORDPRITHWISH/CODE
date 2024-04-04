function tobi(n, l)
{
    // n = n.charCodeAt(0)
    let bin="";
    while(n>0)
    {
        bin=Math.floor(n%2)+bin;
        n=Math.floor(n/2);
    }
    for (let i=bin.length;i<l;i++)
         bin='0'+bin;
    return bin;
}

function frobi(bin){
    let n=0;
    let len=bin.length;
    for(let i=len-1;i>=0;i--)
        n+=(bin.charAt(len-1-i))*Math.pow(2,i);
    return n;

}

function cypher(){
    let base = "";
    for(let i=65;i<=90;i++)
        base+=String.fromCharCode(i);
    for(let i=97;i<=122;i++)
        base+=String.fromCharCode(i);
    for(let i=48;i<=57;i++)
        base+=String.fromCharCode(i);
    base+='+';
    base+='/';
    return base;
}

function encode(str){
    let raw = "";
    let res = "";
    let code = cypher();

    // str.forEach((i) => {
    for(let i=0;i<str.length;i++)   
        raw+=tobi(str.charCodeAt(i),8);
    let len = raw.length;
    while (len%6)
    {
        raw+='0';
        len++;
    }
    for(let i=0;i<len;i+=6)
        res+=code.charAt(frobi(raw.slice(i,i+6)));
    return res;
}

function decode(str){
    let raw = "";
    let res = "";
    let code = cypher();
    str = str.split("");
    str.forEach((i) => {
        raw+=tobi(code.indexOf(i),6);});
    let len = Math.floor(raw.length/8)*8;
    raw=raw.slice(0,len);
    for(let i=0;i<len;i+=8)
        res+=String.fromCharCode(frobi(raw.slice(i,i+8)));
    return res;
}





let str="pop";

let res=decode(encode(str));

console.log(res);
