$(document).ready(function(){

  var deviceID = 'xxx';
  var token    = "xxxx";
  var canSendNewRequest = true;

  $('#dlButton').click(function(){
    var dlSpeed = $('#dlSpeed').val();
    simulate('download', dlSpeed)
  });

  $('#ulButton').click(function(){
    var ulSpeed = $('#ulSpeed').val();
    simulate('upload', ulSpeed)
  });

  function simulate(type, speed) {
    if(canSendNewRequest) {
        canSendNewRequest = false;
        $.post("https://api.particle.io/v1/devices/" + deviceID + "/" + type,
        {
          args: speed,
          access_token: token
        }).done(function(data){
            canSendNewRequest = true;
        });
    }
  }
});
