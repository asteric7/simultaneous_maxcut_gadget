# simultaneous_maxcut_gadget

Analysis of the dictatorship test gadget in "Simultaneous Max-Cut is harder to approximate than Max-Cut" (https://eccc.weizmann.ac.il/report/2019/148/)

----------------

The prover code here is a slight modification of the code from (\*) https://github.com/austrin/max-bisection-analysis
by Per Austrin, Siavosh Benabbas, Konstantinos Georgiou.

The program in (\*) verifies if a certain inequality, involving the Gaussian density function, is true in a specified bounded region. At each iteration, it breaks the region into a few pieces and cheks if the inequality is true in each piece recursively. 
We modify the code in (\*) to suit our purpose. the modification involves changing the inequality and the region. 
