void __cdecl type_string_literal_array(c1_node *literal)

{
  ushort uVar1;
  c1_u8 *pcVar2;
  c1_type *pcVar3;
  uint uVar4;
  c1_u8 *pcVar5;
  c1_u8 *pcVar6;
  c1_type local_10;
  
  local_10.base = (c1_type *)0x0;
  local_10.code = (-(ushort)(((uint)literal->right & 0x10000) != 0) & 0x2001) + 0x11;
  local_10.debug_index = 0;
  local_10.flags = 0;
  local_10.extra.cls = (c1_symbol *)0x0;
  local_10.base = type_intern(&local_10);
  uVar4 = 2;
  if (((uint)literal->right & 0x10000) == 0) {
    uVar4 = 1;
  }
  local_10.extra.count = *(ushort *)&literal->right / uVar4;
  local_10.debug_index = 0;
  local_10.code = 0x83;
  local_10.flags = 0;
  pcVar3 = type_intern(&local_10);
  literal->type = pcVar3;
  pcVar2 = g_arenas[0].cur;
  if (((byte)g_compile_flags_cc & 0x10) != 0) {
    g_arenas[0].cur = g_arenas[0].cur + (*(ushort *)&literal->right + 3 & 0xfffffffc);
    if (g_arenas[0].end < g_arenas[0].cur) {
      arena_grow(g_arenas);
    }
    uVar1 = *(ushort *)&literal->right;
    pcVar5 = literal->left;
    pcVar6 = pcVar2;
    for (uVar4 = (uint)(uVar1 >> 2); uVar4 != 0; uVar4 = uVar4 - 1) {
      *(undefined4 *)pcVar6 = *(undefined4 *)pcVar5;
      pcVar5 = pcVar5 + 4;
      pcVar6 = pcVar6 + 4;
    }
    for (uVar4 = uVar1 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
      *pcVar6 = *pcVar5;
      pcVar5 = pcVar5 + 1;
      pcVar6 = pcVar6 + 1;
    }
    literal->left = pcVar2;
  }
  return;
}

