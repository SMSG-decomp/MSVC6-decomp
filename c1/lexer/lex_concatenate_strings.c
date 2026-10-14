void __cdecl lex_concatenate_strings(c1_string_value *dst,c1_yystype *src)

{
  ushort uVar1;
  ushort uVar2;
  int iVar3;
  uint uVar4;
  fe_arena *a;
  uint uVar5;
  uchar *puVar6;
  uchar *puVar7;
  uchar *puVar8;
  
  iVar3 = 2;
  if ((dst->flags & 1) == 0) {
    iVar3 = 1;
  }
  uVar5 = (uint)dst->length - iVar3;
  uVar1 = (src->string).length;
  uVar4 = uVar1 + uVar5;
  if ((((byte)(src->string).flags ^ (byte)dst->flags) & 1) != 0) {
    diag_error(0x134);
  }
  dst->length = (c1_u16)uVar4;
  if ((uVar4 & 0xffff) == uVar4) {
    if (((dst->flags & 2) != 0) && (*dst->text = 'P', (dst->flags & 2) != 0)) {
      lex_warn_pascal_string_length(dst);
    }
    uVar4 = -(uint)(g_token_arena_index != 3) & g_token_arena_index;
    uVar2 = dst->length;
    a = g_arenas + uVar4;
    puVar8 = a->cur;
    puVar6 = g_arenas[uVar4].end;
    a->cur = puVar8 + (uVar2 + 3 & 0xfffffffc);
    if (puVar6 < puVar8 + (uVar2 + 3 & 0xfffffffc)) {
      arena_grow(a);
    }
    puVar6 = (uchar *)dst->text;
    puVar7 = puVar8;
    for (uVar4 = uVar5 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
      *(undefined4 *)puVar7 = *(undefined4 *)puVar6;
      puVar6 = puVar6 + 4;
      puVar7 = puVar7 + 4;
    }
    for (uVar4 = uVar5 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
      *puVar7 = *puVar6;
      puVar6 = puVar6 + 1;
      puVar7 = puVar7 + 1;
    }
    dst->text = (char *)puVar8;
    puVar6 = (uchar *)(src->string).text;
    puVar8 = puVar8 + uVar5;
    for (uVar4 = (uint)(uVar1 >> 2); uVar4 != 0; uVar4 = uVar4 - 1) {
      *(undefined4 *)puVar8 = *(undefined4 *)puVar6;
      puVar6 = puVar6 + 4;
      puVar8 = puVar8 + 4;
    }
    for (uVar4 = uVar1 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
      *puVar8 = *puVar6;
      puVar6 = puVar6 + 1;
      puVar8 = puVar8 + 1;
    }
    return;
  }
  diag_fatal(0x5b,0xffff);
}

