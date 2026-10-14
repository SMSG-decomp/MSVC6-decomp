void __cdecl pp_if_fold_operator_fragment(fe_pp_value *right,int is_unsigned,fe_pp_value *left)

{
  uint uVar1;
  
  uVar1 = (right->value).hi;
  (left->value).lo = (left->value).lo & (right->value).lo;
  (left->value).hi = (left->value).hi & uVar1;
  left->type = 0x14;
  if (is_unsigned != 0) {
    left->type = 0x2014;
  }
  return;
}

