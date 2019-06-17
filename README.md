Chromosome Mutator
===

This is mutation program of Genetic Algorithm  for my machine learning project.

Definition
---

[8 bit] [n bit] [1+2n bit] [1+2n bit] [...]

8 bit for mutation rate;

b bit for length of node address;

1+2n bit for linker information, 

[1 bit for weight] [n bit for node 1 address] [n bit fornode 2 address]



Usage
---

Use pipe to transmit gene and receive mutated gene,

```shell
cat origin_gene >> mutator >> mutated_gene
```

and of course can been called by another language. The php example: 

```php
$descriptorspec = array( 
    0 => array("pipe", "r"),
    1 => array("pipe", "w"), 
);

$geneString = chr(0x40) . chr(0x9f) . chr(0x50);
$command = "./mutator " . strlen($geneString);

echo "original gene: " . stringToGeneString($geneString) . "\n";

$process = proc_open($command, $descriptorspec, $pipes);

if (is_resource($process)) {
  fwrite($pipes[0], $geneString);
  fclose($pipes[0]);

  $childString = stream_get_contents($pipes[1]);
  fclose($pipes[1]);

  $return_value = proc_close($process);
}
```

