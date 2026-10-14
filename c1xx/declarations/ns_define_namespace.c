byte * __cdecl ns_define_namespace(void *name)

{
  byte *pbVar1;
  char cVar2;
  char *pcVar3;
  int iVar4;
  int iVar5;
  c1_lookup_result *result;
  c1_lookup_entry *pcVar6;
  c1_symbol *pcVar7;
  c1_u8 *pcVar8;
  uint uVar9;
  c1xx_scope *scope;
  char *pcVar10;
  time_t tVar11;
  c1_u8 local_4;
  
  g_compile_flags_c4 = g_compile_flags_c4 & 0xfffffffe;
  local_4 = '\0';
  if (g_current_scope->current->kind != '\0') {
    diag_error(0x366,name);
  }
  if (name == (void *)0x0) {
    if (g_unnamed_namespace_name_made == '\0') {
      g_unnamed_namespace_name_made = '\x01';
      pcVar3 = pp_position_file_name(&g_token_position);
      pcVar8 = g_arenas[0].cur;
      uVar9 = 0xffffffff;
      pcVar10 = pcVar3;
      do {
        if (uVar9 == 0) break;
        uVar9 = uVar9 - 1;
        cVar2 = *pcVar10;
        pcVar10 = pcVar10 + 1;
      } while (cVar2 != '\0');
      g_arenas[0].cur = g_arenas[0].cur + (~uVar9 + 0x42 & 0xfffffffc);
      if (g_arenas[0].end < g_arenas[0].cur) {
        arena_grow(g_arenas);
      }
      g_unnamed_namespace_name = (char *)pcVar8;
      if (g_opt_Brepro == 0) {
        uVar9 = 0xffffffff;
        pcVar10 = g_opt_source_file;
        do {
          if (uVar9 == 0) break;
          uVar9 = uVar9 - 1;
          cVar2 = *pcVar10;
          pcVar10 = pcVar10 + 1;
        } while (cVar2 != '\0');
        uVar9 = SigForPbCb(g_opt_source_file,~uVar9 - 1,0xffffffff);
        tVar11 = time((time_t *)0x0);
        srand((uint)tVar11 ^ uVar9);
        iVar4 = rand();
        iVar5 = rand();
        sprintf(g_unnamed_namespace_name,"?%%%s%d%d",pcVar3,iVar5,iVar4);
      }
      else {
        sprintf((char *)pcVar8,"?%%%s",pcVar3);
      }
    }
    name = name_intern(g_unnamed_namespace_name);
    local_4 = '\x01';
  }
  result = (*g_current_scope->current->vtbl->lookup)(g_current_scope->current,name,1);
  if (result != (c1_lookup_result *)0x0) {
    pcVar6 = lookup_check_ambiguous_symbol(result,'\x01');
    if (pcVar6 != (c1_lookup_entry *)0x0) {
      pcVar7 = pcVar6->sym;
      if ((pcVar7->kind & 0x1f) == 0x19) {
        scope = *(c1xx_scope **)pcVar7->type;
        pbVar1 = (byte *)((int)&pcVar7->type->base + 2);
        *pbVar1 = *pbVar1 | 2;
      }
      else {
        diag_error(0x367,name);
        pcVar7->flags3 = pcVar7->flags3 | 4;
        scope = (c1xx_scope *)g_arenas[0].cur;
        g_arenas[0].cur = g_arenas[0].cur + 0x24;
        if (g_arenas[0].end < g_arenas[0].cur) {
          arena_grow(g_arenas);
        }
        if (scope == (c1xx_scope *)0x0) {
          scope = (c1xx_scope *)0x0;
        }
        else {
          *(c1_u8 *)((int)scope + 4) = '\0';
          *(c1_u8 *)((int)scope + 5) = '\0';
          *(c1_u8 *)((int)scope + 6) = '\0';
          *(c1_u8 *)((int)scope + 7) = '\0';
          *(c1_u8 *)((int)scope + 8) = '\0';
          *(c1_u8 *)((int)scope + 0xc) = '\0';
          *(c1_u8 *)((int)scope + 0xd) = '\0';
          *(c1_u8 *)((int)scope + 0xe) = '\0';
          *(c1_u8 *)((int)scope + 0xf) = '\0';
          *(c1_u8 *)((int)scope + 0x10) = '\0';
          *(c1_u8 *)((int)scope + 0x11) = '\0';
          *(c1_u8 *)((int)scope + 0x12) = '\0';
          *(c1_u8 *)((int)scope + 0x13) = '\0';
          *(c1_u8 *)((int)scope + 0x18) = 0xff;
          *(c1_u8 *)((int)scope + 0x19) = '\0';
          *(c1_u8 *)((int)scope + 0x1a) = '\0';
          *(c1_u8 *)((int)scope + 0x1b) = '\0';
          *(c1_u8 *)((int)scope + 0x1c) = '\0';
          *(c1_u8 *)((int)scope + 0x1d) = '\0';
          *(c1_u8 *)((int)scope + 0x1e) = '\0';
          *(c1_u8 *)((int)scope + 0x1f) = '\0';
          *(c1_symbol **)((int)scope + 0x20) = pcVar7;
          *(undefined ***)scope = &PTR_hash_scope_has_entries_104cef40;
          pcVar8 = pool_alloc_raw(&g_scope_pool,0x400);
          *(c1_u8 **)((int)scope + 0x14) = pcVar8;
        }
      }
      goto LAB_104acaa9;
    }
  }
  pcVar7 = ns_new_namespace(name,local_4);
  scope = *(c1xx_scope **)pcVar7->type;
  (*g_current_scope->current->vtbl->insert)(pcVar7);
LAB_104acaa9:
  scope_push_child(g_current_scope,scope);
  g_paren_level_flags[g_paren_depth] = g_paren_level_flags[g_paren_depth] & 0xfd;
  return &pcVar7->kind;
}

