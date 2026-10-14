void __cdecl lex_copy_text_to_arena(c1_string_value *out,c1_u8 *text,uint len,int arena)

{
  uchar *puVar1;
  fe_arena *a;
  uint uVar2;
  uchar *puVar3;
  
  a = g_arenas + arena;
  puVar1 = a->cur;
  puVar3 = g_arenas[arena].end;
  a->cur = puVar1 + (len + 3 & 0xfffffffc);
  if (puVar3 < puVar1 + (len + 3 & 0xfffffffc)) {
    arena_grow(a);
  }
  puVar3 = puVar1;
  for (uVar2 = len >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
    *(undefined4 *)puVar3 = *(undefined4 *)text;
    text = text + 4;
    puVar3 = puVar3 + 4;
  }
  for (uVar2 = len & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
    *puVar3 = *text;
    text = text + 1;
    puVar3 = puVar3 + 1;
  }
  out->length = (c1_u16)len;
  out->text = (char *)puVar1;
  return;
}

