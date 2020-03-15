BNN Tools
===

This is a tool package of Genetic Algorithm  for my machine learning project which are using BNN (Boolean Neural Network).

Definition
---

The binary chromosome defined as shown below:

![](./img/spec-binary-chromosome.png)

The length of node id (address), the variable n, are defined by addressing space, which the first byte in the file/string.



Usage
---
### Random Generator
To create randomly chromosome.
Allowed options:
  --help                produce help message
  --address arg         length of addressing space
  --gene arg            how many genes will generated

```shell
./generator --address 12 --gene 100 > test_gene
```

### Decoder
To parse gene and convert to Json.
```shell
./decoder --input-file test_gene > test_gene.json
```

### Mutator (temporary not working)
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

