c1_node * __cdecl
fold_truncate_to_type_width(uint lo,int hi,c1_type *type,c1_node *operand,c1_node *typed_by)

{
  ushort uVar1;
  byte count;
  longlong lVar2;
  ulonglong uVar3;
  
  uVar1 = type->code;
  uVar3 = CONCAT44(hi,lo);
  if ((-1 < (char)uVar1) &&
     ((((uVar1 & 0x2000) != 0 ||
       ((((g_ms_extensions == '\0' && ((uVar1 & 0xfff) == 0x11)) && ((uVar1 & 0x1000) == 0)) &&
        (g_opt_J_unsigned_char != '\0')))) ||
      ((uVar3 = CONCAT44(hi,lo), -1 < hi && ((0 < hi || (uVar3 = CONCAT44(hi,lo), lo != 0)))))))) {
    count = ('\b' - (&g_type_rank_table)[uVar1 & 0xf]) * '\b';
    lVar2 = _allshl(count,lo,hi);
    uVar3 = _aullshr(count,(uint)((ulonglong)lVar2 >> 0x20),(uint)lVar2);
  }
  operand->type = typed_by->type;
  operand->left = (void *)(int)uVar3;
  operand->right = (void *)(int)(uVar3 >> 0x20);
  return operand;
}

