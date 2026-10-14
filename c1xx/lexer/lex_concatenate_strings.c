void __cdecl lex_concatenate_strings(c1_string_value *dst,c1_string_value *src)

{
  ushort uVar1;
  ushort uVar2;
  int iVar3;
  c1_arena *a;
  uint uVar4;
  uint uVar5;
  c1_u8 *pcVar6;
  c1_u8 *pcVar7;
  c1_u8 *pcVar8;
  
  iVar3 = 2;
  if ((dst->flags & 1) == 0) {
    iVar3 = 1;
  }
  uVar5 = (uint)dst->length - iVar3;
  uVar1 = src->length;
  uVar4 = uVar1 + uVar5;
  if ((((byte)src->flags ^ (byte)dst->flags) & 1) != 0) {
    diag_error(0x134);
  }
  dst->length = (c1_u16)uVar4;
  if ((uVar4 & 0xffff) == uVar4) {
    if (((dst->flags & 2) != 0) && (*dst->text = 'P', (dst->flags & 2) != 0)) {
      lex_warn_pascal_string_length((int *)dst);
    }
    if ((g_token_arena_index == 5) ||
       (iVar3 = g_token_arena_index, (g_compile_flags_c8 & 0x2000000) != 0)) {
      iVar3 = 0;
    }
    uVar2 = dst->length;
    a = g_arenas + iVar3;
    pcVar8 = a->cur;
    pcVar6 = g_arenas[iVar3].end;
    a->cur = pcVar8 + (uVar2 + 3 & 0xfffffffc);
    if (pcVar6 < pcVar8 + (uVar2 + 3 & 0xfffffffc)) {
      arena_grow(a);
    }
    pcVar6 = dst->text;
    pcVar7 = pcVar8;
    for (uVar4 = uVar5 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
      *(undefined4 *)pcVar7 = *(undefined4 *)pcVar6;
      pcVar6 = pcVar6 + 4;
      pcVar7 = pcVar7 + 4;
    }
    for (uVar4 = uVar5 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
      *pcVar7 = *pcVar6;
      pcVar6 = pcVar6 + 1;
      pcVar7 = pcVar7 + 1;
    }
    dst->text = pcVar8;
    pcVar6 = src->text;
    pcVar8 = pcVar8 + uVar5;
    for (uVar4 = (uint)(uVar1 >> 2); uVar4 != 0; uVar4 = uVar4 - 1) {
      *(undefined4 *)pcVar8 = *(undefined4 *)pcVar6;
      pcVar6 = pcVar6 + 4;
      pcVar8 = pcVar8 + 4;
    }
    for (uVar4 = uVar1 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
      *pcVar8 = *pcVar6;
      pcVar6 = pcVar6 + 1;
      pcVar8 = pcVar8 + 1;
    }
    return;
  }
  diag_fatal(0x5b,0xffff);
}

