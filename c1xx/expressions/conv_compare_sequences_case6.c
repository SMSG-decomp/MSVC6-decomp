int __thiscall conv_compare_sequences_case6(char flip,c1_type *type_a,c1_type *type_b)

{
  int iVar1;
  
  iVar1 = conv_compare_class_derivation(flip,(type_a->extra).cls,(type_b->extra).cls);
  return iVar1;
}

