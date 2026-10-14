ushort __cdecl expr_warn_array_bounds_overflow(c1_symbol *sym,c1_node *node)

{
  short sVar1;
  ushort uVar2;
  
  sVar1 = 2;
  if (((uint)node->right & 0x10000) == 0) {
    sVar1 = 1;
  }
  uVar2 = (short)*(undefined4 *)(((uint)sym->type & -(uint)((sym->type->code & 0x80) != 0)) + 8) *
          sVar1;
  if ((uVar2 != 0) && (uVar2 < *(ushort *)&node->right)) {
    if (uVar2 < (ushort)(*(ushort *)&node->right - 1)) {
      diag_warning(1,0x2d,node->left);
    }
    return uVar2;
  }
  return *(ushort *)&node->right;
}

