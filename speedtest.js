var speedTest = require('speedtest-net')();

speedTest.on('downloadspeed',function(speed){
  console.log('Download speed:',(speed/1000).toFixed(2),'KB/s');
});

speedTest.on('uploadspeed',function(speed){
  console.log('Upload speed:',(speed/1000).toFixed(2),'KB/s');
});

speedTest.on('downloadspeedprogress',function(speed){
  //  console.dir(speedTest);
    console.log('Download speed (in progress):',(speed/1000).toFixed(2),'KB/s');
});

speedTest.on('uploadspeedprogress',function(speed){
  console.log('Upload speed (in progress):',(speed/1000).toFixed(2),'KB/s');
});

// speedTest.on('data',function(data){
//    console.dir(data);
// });
