void __cdecl pp_define_install(fe_name *name,int kind,fe_macro *binding,uint length,c1_u8 *text)

{
  fe_macro_definition *pfVar1;
  fe_name **ppfVar2;
  fe_macro *macro;
  byte *body;
  uint uVar3;
  c1_u8 *pcVar4;
  
  body = g_define_text_ptr;
  if (length == 0) {
    body = (byte *)"";
  }
  pch_record_macro_definition((byte *)name->text,body,(short)kind);
  if (binding != (fe_macro *)0x0) {
    pfVar1 = binding->def;
    if (pfVar1->kind < -3) {
      diag_warning(1,0x75,g_last_name,"#define");
      return;
    }
    if ((kind == -3) || (kind == pfVar1->kind)) {
      if (length == 0) {
        uVar3 = (uint)(pfVar1->text[0] != '\0');
      }
      else {
        uVar3 = str_differ_n((char *)text,(char *)pfVar1->text,length - 1);
      }
      if (uVar3 == 0) {
        return;
      }
    }
    diag_begin_global(g_token_position);
    diag_warning(1,5,g_last_name);
    diag_note(0x18a7,binding->def->position,g_last_name);
    diag_end_global();
  }
  if (g_macro_definition_pool_left < 8) {
    pool_reserve((c1xx_pool *)&g_macro_definition_pool,8);
  }
  macro = g_macro_definition_pool;
  g_macro_definition_pool_left = g_macro_definition_pool_left - 8;
  ppfVar2 = &g_macro_definition_pool->name;
  g_macro_definition_pool = g_macro_definition_pool + 1;
  *ppfVar2 = g_last_name;
  pcVar4 = g_arenas[0].cur;
  g_arenas[0].cur = g_arenas[0].cur + (length + 0x13 & 0xfffffffc);
  if (g_arenas[0].end < g_arenas[0].cur) {
    arena_grow(g_arenas);
  }
  macro->def = (fe_macro_definition *)pcVar4;
  if (length != 0) {
    pcVar4 = pcVar4 + 0xc;
    for (uVar3 = length >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
      *(undefined4 *)pcVar4 = *(undefined4 *)text;
      text = text + 4;
      pcVar4 = pcVar4 + 4;
    }
    for (uVar3 = length & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
      *pcVar4 = *text;
      text = text + 1;
      pcVar4 = pcVar4 + 1;
    }
  }
  g_last_name->flags = g_last_name->flags | 0x80000;
  g_last_name->macro = macro;
  macro->def->kind = (char)kind;
  macro->def->position = g_token_position;
  (*g_il_emitter->vtbl->define_macro)(g_il_emitter,(int *)macro);
  return;
}

