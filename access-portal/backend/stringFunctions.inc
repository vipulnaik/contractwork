<?php

function printWorker($worker) {
  if ($worker == "Private") {
    print '<tr><td>Private</td>';
  } else {
    print '<tr><td><a href="/worker.php?worker='.urlencode($worker).'">'.$worker.'</a></td>';
  }
}

function cleanNotes($notes) {
  $notesList = explode(" ",$notes);
  $augmentedNotes = "";
  foreach ($notesList as $notesWord) {
    if (substr($notesWord,0,4) == "http") {
      $augmentedNotes = $augmentedNotes . '<a href="'.$notesWord.'">'.$notesWord.'</a> ';
    } else {
      $augmentedNotes = $augmentedNotes . $notesWord . " ";
    }
  }
  return $augmentedNotes;
}

function showTocLine($mysqli, $value, $query) {
  if ($stmt = $mysqli->prepare($query)) {
    $stmt->bind_param("s", $value);
    $stmt->execute();
    // Get result to allow the next query to happen, but we only need the
    // number of rows so don't bother assigning to a variable
    $stmt->get_result();
    if ($mysqli->affected_rows > 0) {
      return true;
    }
  }
  return false;
}
?>
