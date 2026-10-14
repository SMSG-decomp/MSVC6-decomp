void __cdecl pp_define_finish(c1_u8 *text,uint length,int formal_count)

{
  fe_macro *binding;
  fe_macro_definition *pfVar1;
  uchar *macro;
  uint uVar2;
  uchar *puVar3;
  
  if (length == 0) {
    text = (c1_u8 *)length;
  }
  if (g_last_name != g_name_defined) {
    binding = g_last_name->macro;
    if ((g_include_depth == 0) && (g_pch_directive_mode != 0)) {
      pp_define_install(g_last_name,formal_count,binding,length,text);
      return;
    }
    if (binding != (fe_macro *)0x0) {
      pfVar1 = binding->def;
      if (pfVar1->kind < -3) goto LAB_106291b3;
      if ((formal_count == -3) || (formal_count == pfVar1->kind)) {
        if (length == 0) {
          uVar2 = (uint)(pfVar1->text[0] != '\0');
        }
        else {
          uVar2 = str_differ_n((char *)text,(char *)pfVar1->text,length - 1);
        }
        if (uVar2 == 0) {
          return;
        }
      }
      diag_begin_global(g_token_position);
      diag_warning(1,5,g_last_name);
      diag_note(0x18a7,binding->def->position,g_last_name);
      diag_end_global();
    }
    if (g_macro_definition_pool.left < 8) {
      pool_reserve(&g_macro_definition_pool,8);
    }
    macro = g_macro_definition_pool.cur;
    g_macro_definition_pool.left = g_macro_definition_pool.left - 8;
    puVar3 = g_macro_definition_pool.cur + 8;
    *(fe_name **)g_macro_definition_pool.cur = g_last_name;
    g_macro_definition_pool.cur = puVar3;
    puVar3 = g_arenas[0].cur;
    g_arenas[0].cur = g_arenas[0].cur + (length + 0x13 & 0xfffffffc);
    if (g_arenas[0].end < g_arenas[0].cur) {
      arena_grow(g_arenas);
    }
    *(uchar **)(macro + 4) = puVar3;
    if (length != 0) {
      puVar3 = puVar3 + 0xc;
      for (uVar2 = length >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
        *(undefined4 *)puVar3 = *(undefined4 *)text;
        text = text + 4;
        puVar3 = puVar3 + 4;
      }
      for (uVar2 = length & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
        *puVar3 = *text;
        text = text + 1;
        puVar3 = puVar3 + 1;
      }
    }
    g_last_name->flags = g_last_name->flags | 0x80000;
    g_last_name->macro = (fe_macro *)macro;
    *(char *)(*(int *)(macro + 4) + 4) = (char)formal_count;
    *(int *)(*(int *)(macro + 4) + 8) = g_token_position;
    (*g_il_emitter->vtbl->define_macro)(g_il_emitter,(int *)macro);
    return;
  }
LAB_106291b3:
  diag_warning(1,0x75,g_last_name,"#define");
  return;
}

