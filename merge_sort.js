const { spawn } = require('child_process');

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

    if (arr.length <= 100) {
        devide(ara);
        devide(arb);
    } else {
        const worker1 = spawn(process.execPath, [__filename], {
            stdio: ['inherit', 'inherit', 'inherit', 'ipc']
        });
        const worker2 = spawn(process.execPath, [__filename], {
            stdio: ['inherit', 'inherit', 'inherit', 'ipc']
        });

        worker1.send(ara);
        worker2.send(arb);

        worker1.on('message', (message) => {
            merge(arr, message, arb);
        });

        worker2.on('message', (message) => {
            merge(arr, ara, message);
        });
    }

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

// const len = 1000000;
const len = 10000;
const arr = arrmaker(len);
mergesort(arr);
