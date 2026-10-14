void __cdecl parse_resolve_candidate_token(char *token)

{
  ushort uVar1;
  c1_type *type;
  int iVar2;
  int *piVar3;
  c1_type_extra cVar4;
  c1_u8 *pcVar5;
  
  type = *(c1_type **)(token + 0x20);
  uVar1 = type->code;
  if ((uVar1 & 0x4f0) == 0) {
    if (-1 < g_class_depth) {
      cVar4 = type->extra;
      *token = -0x27;
      pcVar5 = g_arenas[4].cur;
      g_arenas[4].cur = g_arenas[4].cur + 4;
      if (g_arenas[4].end < g_arenas[4].cur) {
        arena_grow(g_arenas + 4);
      }
      if (pcVar5 != (c1_u8 *)0x0) {
        *(c1_type_extra *)pcVar5 = cVar4;
        *(c1_u8 **)(token + 8) = pcVar5;
        return;
      }
      token[8] = '\0';
      token[9] = '\0';
      token[10] = '\0';
      token[0xb] = '\0';
      return;
    }
    cVar4 = (c1_type_extra)((c1_type_extra *)(token + 0x24))->cls;
    if (((cVar4.cls)->flags2 & 0x60) != 0) {
LAB_10457e6c:
      tree_new_type_token_node((c1xx_token *)token,type);
      return;
    }
    if ((((g_parse_block_record_depth != 1) || (*token != -0x5c)) ||
        ((g_compile_flags_c8 & 0x100) != 0)) || ((g_paren_level_flags[g_paren_depth] & 2) != 0)) {
      if (((uVar1 & 0xfff) != 0x802) && (((char)uVar1 < '\0' || ((uVar1 & 0xfff) != 0x801)))) {
        cVar4 = type->extra;
      }
      *token = -0x27;
      pcVar5 = g_arenas[4].cur;
      g_arenas[4].cur = g_arenas[4].cur + 4;
      if (g_arenas[4].end < g_arenas[4].cur) {
        arena_grow(g_arenas + 4);
      }
      if (pcVar5 == (c1_u8 *)0x0) {
        pcVar5 = (c1_u8 *)0x0;
      }
      else {
        *(c1_type_extra *)pcVar5 = cVar4;
      }
      *(c1_u8 **)(token + 8) = pcVar5;
      g_paren_level_flags[g_paren_depth] = g_paren_level_flags[g_paren_depth] | 2;
      return;
    }
  }
  else {
    if ((g_paren_level_flags[g_paren_depth] & 3) != 0) {
      iVar2 = *(int *)(token + 0x24);
      if (iVar2 != 0) {
        *token = -0x27;
        piVar3 = arena_alloc(g_arenas + 4,4);
        if (piVar3 != (int *)0x0) {
          *piVar3 = iVar2;
          *(int **)(token + 8) = piVar3;
          return;
        }
        token[8] = '\0';
        token[9] = '\0';
        token[10] = '\0';
        token[0xb] = '\0';
        return;
      }
      goto LAB_10457e6c;
    }
    if ((*token == -0x5c) && ((g_compile_flags_c4 & 0x40000000) != 0)) {
      g_compile_flags_c4 = g_compile_flags_c4 & 0xbfffffff;
      (*g_token_source->stream->vtbl->unget)(g_token_source->stream,token);
      parse_classify_candidate_token('\x01');
      return;
    }
  }
  token_set_kind_24(token);
  return;
}

