c1_tag_symbol * __cdecl
decl_warn_type_definition_in_parentheses(void *name,ushort kind,int *insert,int definition)

{
  c1_type_declarator *pcVar1;
  c1_symbol *tag;
  int *piVar2;
  c1_declaration *decl;
  int level;
  
  decl = (c1_declaration *)g_arenas[3].cur;
  g_arenas[3].cur = g_arenas[3].cur + 0x30;
  if (g_arenas[3].end < g_arenas[3].cur) {
    arena_grow(g_arenas + 3);
  }
  if (decl == (c1_declaration *)0x0) {
    decl = (c1_declaration *)0x0;
  }
  else {
    decl->name = name;
    *(uchar *)((int)decl + 0x24) = '\r';
    *(uchar *)((int)decl + 0x25) = '\0';
    *(uchar *)((int)decl + 0x26) = '\0';
    *(uchar *)((int)decl + 0x27) = '\0';
    pcVar1 = arena_alloc(g_arenas + 3,0x38);
    if (pcVar1 == (c1_type_declarator *)0x0) {
      *(uchar *)((int)decl + 4) = '\0';
      *(uchar *)((int)decl + 5) = '\0';
      *(uchar *)((int)decl + 6) = '\0';
      *(uchar *)((int)decl + 7) = '\0';
      *(int *)((int)decl + 0x18) = g_token_position;
    }
    else {
      pcVar1 = decl_new_declarator(pcVar1,decl->name);
      *(c1_type_declarator **)((int)decl + 4) = pcVar1;
      *(int *)((int)decl + 0x18) = g_token_position;
    }
  }
  decl_tag_declarator_set_kind(decl,kind,(void **)insert,definition);
  if (name == (void *)0x0) {
    if (0 < g_paren_depth) {
      diag_warning(1,0x74);
    }
    decl->name = g_name_unnamed;
    tag = sym_new_from_declarator(decl,-1);
  }
  else {
    decl->name = name;
    tag = sym_new_from_declarator(decl,-1);
    if (0 < g_paren_depth) {
      if (g_ms_extensions == '\0') {
        level = 1;
      }
      else {
        level = 4;
      }
      diag_warning(level,0x73,tag);
      if (((char)definition == '\0') && (g_ms_extensions != '\0')) {
        *insert = 0;
        piVar2 = scope_skip_prototype_scopes(g_current_scope);
        (**(code **)(*piVar2 + 4))(tag);
      }
    }
  }
  if ((g_browse_file != (char *)0x0) && ((g_block_depth == '\0' || (g_opt_FR_browse != 0)))) {
    (*g_il_emitter->vtbl->define_symbol)(g_il_emitter,tag);
  }
  g_tag_found_in_current_scope = 1;
  return (c1_tag_symbol *)tag;
}

