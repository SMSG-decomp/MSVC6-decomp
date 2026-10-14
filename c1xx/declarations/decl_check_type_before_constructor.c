int __fastcall decl_check_type_before_constructor(int *state)

{
  char cVar1;
  void *pvVar2;
  void *pvVar3;
  c1xx_token *pcVar4;
  c1_u8 *token;
  byte *pbVar5;
  c1_symbol *pcVar6;
  c1_type *pcVar7;
  int iVar8;
  undefined4 *puVar9;
  c1_u8 *pcVar10;
  
  if ((state[0xc] == 0) && ((short)state[0x10] == 0)) {
    g_compile_flags_c4 = g_compile_flags_c4 | 0x400;
    pcVar4 = lex_classify_type_name((c1xx_token *)*state);
    g_compile_flags_c4 = g_compile_flags_c4 & 0xfffffbff;
    *state = (int)pcVar4;
    if (pcVar4->code != '\x1e') {
      return 2 - (uint)(state[2] != 0);
    }
    decl_specifier_set_class_type(state);
    return 0;
  }
  if ((((g_paren_depth == 0) && (g_block_depth == '\0')) && (-1 < g_class_depth)) &&
     ((g_compile_flags_c4 & 0x10000000) == 0)) {
    cVar1 = *(char *)*state;
    if (cVar1 == '\x06') {
      pvVar2 = *(void **)((char *)*state + 8);
      pvVar3 = class_current_definition_name();
      if (pvVar3 != pvVar2) goto LAB_104078d8;
      if (g_token_arena_index == 0) {
        token = pool_alloc_raw(&g_pool_default,0x30);
      }
      else {
        token = arena_alloc(g_arenas + g_token_arena_index,0x30);
      }
      if (token == (c1_u8 *)0x0) {
        token = (c1_u8 *)0x0;
      }
      else {
        puVar9 = (undefined4 *)*state;
        pcVar10 = token;
        for (iVar8 = 0xc; iVar8 != 0; iVar8 = iVar8 + -1) {
          *(undefined4 *)pcVar10 = *puVar9;
          puVar9 = puVar9 + 1;
          pcVar10 = pcVar10 + 4;
        }
      }
      pbVar5 = lex_compose_qualified_name((char *)token,0);
      if (*pbVar5 != 0x96) {
        if ((*pbVar5 == 6) &&
           (pvVar3 = class_current_definition_name(), pvVar3 == *(void **)(pbVar5 + 8))) {
          diag_error(0x17c,0x49,pvVar2);
          *(undefined2 *)(state + 0x10) = 0;
          pcVar6 = class_current_definition();
          state[0xd] = (int)pcVar6;
          pcVar7 = sym_resolved_type_mark_used(pcVar6);
          state[0xf] = 0;
          state[0xc] = (int)pcVar7;
          return 0;
        }
        g_compile_flags_c4 = g_compile_flags_c4 | 1;
        *state = (int)pbVar5;
        return 1;
      }
      *state = (int)pbVar5;
    }
    else if (cVar1 != -0x6a) goto LAB_104078d8;
    iVar8 = **(int **)(*state + 8);
    if (((*(byte *)(iVar8 + 1) & 0x10) == 0x10) &&
       (pvVar2 = *(void **)(*(int *)(**(int **)(iVar8 + 0x14) + 8) + 8),
       pvVar3 = class_current_definition_name(), pvVar2 == pvVar3)) {
      diag_error(0x17c,0x53,iVar8);
      *(undefined2 *)(state + 0x10) = 0;
      pcVar6 = class_current_definition();
      state[0xd] = (int)pcVar6;
      pcVar7 = sym_resolved_type_mark_used(pcVar6);
      state[0xf] = 0;
      state[0xc] = (int)pcVar7;
      return 0;
    }
  }
LAB_104078d8:
  g_compile_flags_c4 = g_compile_flags_c4 | 1;
  return 1;
}

