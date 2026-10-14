void __cdecl lex_copy_text_to_arena(c1_string_value *out,c1_u8 *text,uint len,int arena)

{
  c1_u8 *pcVar1;
  c1_arena *a;
  uint uVar2;
  c1_u8 *pcVar3;
  
  a = g_arenas + arena;
  pcVar1 = a->cur;
  pcVar3 = g_arenas[arena].end;
  a->cur = pcVar1 + (len + 3 & 0xfffffffc);
  if (pcVar3 < pcVar1 + (len + 3 & 0xfffffffc)) {
    arena_grow(a);
  }
  pcVar3 = pcVar1;
  for (uVar2 = len >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
    *(undefined4 *)pcVar3 = *(undefined4 *)text;
    text = text + 4;
    pcVar3 = pcVar3 + 4;
  }
  for (uVar2 = len & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
    *pcVar3 = *text;
    text = text + 1;
    pcVar3 = pcVar3 + 1;
  }
  out->length = (c1_u16)len;
  out->text = pcVar1;
  return;
}

