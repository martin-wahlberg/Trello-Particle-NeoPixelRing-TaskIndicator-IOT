<?php

$trelloKey = "YOUR-TRELLO-API-KEY"
$trelloTOKEN = "YOUR-TRELLO-API-TOKEN"
$particleTOKEN = "YOUR-PARTICLE-TOKEN"
$listId = "YOUR-TRELLO-LIST-ID"

//Gets new tasks
$ch = curl_init();

curl_setopt($ch, CURLOPT_URL, "https://api.trello.com/1/lists/$listId/cards?key=$trelloKey&token=$trelloToken&fields=name");
curl_setopt($ch, CURLOPT_RETURNTRANSFER, 1);

$result = curl_exec($ch);
if (curl_errno($ch)) {
    echo 'Error:' . curl_error($ch);
}
curl_close ($ch);

//COUNTS NEW TASKS
$trello_array = json_decode($result,true);
$trelloNumber = count($trello_array);


//Calling particle function
$ch = curl_init();
//Plus one because of troubles passing 1.
$particleNumber = $trelloNumber + 1;
curl_setopt($ch, CURLOPT_URL, "https://api.particle.io/v1/devices/57002d000b51353335323535/TrelloComand");
curl_setopt($ch, CURLOPT_RETURNTRANSFER, 1);
curl_setopt($ch, CURLOPT_POSTFIELDS, "arg=$particleNumber&access_token=$particleToken");
curl_setopt($ch, CURLOPT_POST, 1);

$headers = array();
$headers[] = "Content-Type: application/x-www-form-urlencoded";
curl_setopt($ch, CURLOPT_HTTPHEADER, $headers);

$result = curl_exec($ch);
if (curl_errno($ch)) {
    echo 'Error:' . curl_error($ch);
}
curl_close ($ch);
?>
