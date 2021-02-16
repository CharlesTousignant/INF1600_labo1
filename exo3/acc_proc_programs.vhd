use work.acc_proc_def.all;

package acc_proc_programs is

   -- Le contenu de la memoire est uint16, 
   -- ce qui explique l'utilisation de fonctions
   -- de converssion
   constant program_0 : memtype := (
      to_uint16((ld,   7)),   --  0 
      to_uint16((br,   3)),   --  1
      to_uint16((ld,   8)),   --  2
      to_uint16((brz,  5)),   --  3
      to_uint16((add,  9)),   --  4
      to_uint16((brnz, 1)),   --  5
      to_uint16((stop, 0)),   --  6
      +2,                     --  7
      +1,                     --  8
      int16_to_uint16(-1),    --  9
      others => 0
   );

   -- Programme utilise pour Q2
   constant program_1 : memtype := (
      -- ajouter votre programme ici, une ligne par instruction
      to_uint16((lda, 16)), -- 0
      
      to_uint16((ld, 17)), --1
      to_uint16((addx, 00)), --2

      to_uint16((adda, 17)), --3
      to_uint16((addx, 00)), --4
      to_uint16((adda, 17)), --5
      to_uint16((sti, 00)), --6

      to_uint16((sta, 16)), --7
      to_uint16((ld, 16)), --8
      to_uint16((sub, 15)), --9

      to_uint16((brz, 14)), --10
      to_uint16((suba, 17)), --11
      to_uint16((sta, 16)), --12
      to_uint16((br, 0)), --13
      to_uint16((stop, 0)), --14  FIN 

      +22,                    --15  addresse memoie de depart = 17, nombre de termes de la suite a calculer = 5, 17 + 5 = 22
      +17,                     --16
      +1,                      --17 S(0)
      +2,                      --18 S(1)
      --Le programme prend autant de lignes que la version sans utiliser des boucles et de registre MA,
      --cependant, si on voulait trouver les 10, 20 ou 100 premieres valeures de la suite, on aurait simplement a
      --changer la valeure stockee a la ligne 15.
      others => 0
   );
   
end acc_proc_programs;

package body acc_proc_programs is  
end acc_proc_programs;
