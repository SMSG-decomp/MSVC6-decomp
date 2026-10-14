c1_node * __cdecl
type_fold_integer_constant_fragment
          (c1_type *type,uint value_lo,int value_hi,c1_node *k,c1_node *unary)

{
  ushort uVar1;
  byte count;
  longlong lVar2;
  ulonglong uVar3;
  
  uVar1 = type->code;
  uVar3 = CONCAT44(value_hi,value_lo);
  if ((-1 < (char)uVar1) &&
     ((((uVar1 & 0x2000) != 0 ||
       ((((uVar1 & 0xfff) == 0x11 && ((uVar1 & 0x1000) == 0)) && (g_opt_J_unsigned_char != '\0'))))
      || ((uVar3 = CONCAT44(value_hi,value_lo), -1 < value_hi &&
          ((0 < value_hi || (uVar3 = CONCAT44(value_hi,value_lo), value_lo != 0)))))))) {
    count = ('\b' - (&g_type_rank_table)[uVar1 & 0xf]) * '\b';
    lVar2 = _allshl(count,value_lo,value_hi);
    uVar3 = _aullshr(count,(uint)((ulonglong)lVar2 >> 0x20),(uint)lVar2);
  }
  if (((byte)g_compile_flags_cc & 8) != 0) {
    k = tree_copy_to_arena(k,5);
  }
  k->type = unary->type;
  k->left = (void *)(int)uVar3;
  k->right = (void *)(int)(uVar3 >> 0x20);
  return k;
}

