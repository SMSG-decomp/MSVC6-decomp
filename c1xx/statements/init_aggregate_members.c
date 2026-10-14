int __cdecl init_aggregate_members(c1_node *value)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = init_descend_to_member((int)value);
  if (uVar1 == 0) {
    return 0;
  }
  do {
    iVar2 = sym_has_scalar_type(g_init_level->sym);
    if (iVar2 != 0) {
      return 1;
    }
    iVar2 = init_is_char_array_string_init(g_init_level->sym,value);
    if (iVar2 != 0) {
      return 1;
    }
    if ((g_init_level->flags & 0x50) != 0) {
      return 1;
    }
    uVar1 = init_descend_to_member((int)value);
  } while (uVar1 != 0);
  iVar2 = init_aggregate_members_fail_tail();
  return iVar2;
}

