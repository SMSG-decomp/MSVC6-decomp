void __cdecl type_string_literal_array(c1_node *literal)

{
  c1_type *pcVar1;
  uint uVar2;
  c1_type local_10;
  
  if (((uint)literal->right & 0x10000) == 0) {
    local_10.code = 0x11;
    if ((g_ms_extensions != '\0') && (g_opt_J_unsigned_char != '\0')) {
      local_10.code = 0x2011;
    }
  }
  else {
    local_10.code = 0x2012;
  }
  local_10.base = (c1_type *)0x0;
  local_10.debug_index = 0;
  local_10.flags = 0;
  local_10.extra.sym = (c1_symbol *)0x0;
  local_10.base = type_intern(&local_10);
  uVar2 = 2;
  if (((uint)literal->right & 0x10000) == 0) {
    uVar2 = 1;
  }
  local_10.extra.count = *(ushort *)&literal->right / uVar2;
  local_10.debug_index = 0;
  local_10.code = 0x83;
  local_10.flags = 0;
  pcVar1 = type_intern(&local_10);
  literal->type = pcVar1;
  return;
}

