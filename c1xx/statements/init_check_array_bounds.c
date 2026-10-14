ushort __cdecl init_check_array_bounds(c1_symbol *sym,c1_node *node)

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
    diag_error(0x75,node->left);
    return uVar2;
  }
  return *(ushort *)&node->right;
}

