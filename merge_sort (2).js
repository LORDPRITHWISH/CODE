function arrprint(arr) {
    console.log(arr.join(' '));
}

function merge(arr, ar, br) {
    let i = 0, j = 0, k = 0;
    while (j < ar.length && k < br.length) {
        if (ar[j] < br[k])
            arr[i++] = ar[j++];
        else
            arr[i++] = br[k++];
    }

    while (j < ar.length)
        arr[i++] = ar[j++];

    while (k < br.length)
        arr[i++] = br[k++];
}

function devide(arr) {
    const mid = Math.floor(arr.length / 2);
    const ara = arr.slice(0, mid);
    const arb = arr.slice(mid);
    
    if (arr.length <= 1)
        return arr;

    devide(ara);
    devide(arb);

    merge(arr, ara, arb);
}

function mergesort(arr) {
    const start = new Date();
    devide(arr);
    const end = new Date();
    console.log((end - start) / 1000 + 's');
}

function arrmaker(len) {
    const arr = [];
    for (let i = 0; i < len; i++)
        arr.push(Math.floor(Math.random() * len));
    return arr;
}

// const len = 100000000;
const len = 100000000;
// const len = 1000000;
const arr = arrmaker(len);
mergesort(arr);
