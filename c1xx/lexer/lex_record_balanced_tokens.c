void __cdecl lex_record_balanced_tokens(int depth)

{
  uint uVar1;
  byte *next_token;
  c1_arena *a;
  c1_symbol *qualifier;
  uint *token;
  int iVar2;
  c1xx_token_stream *this;
  int paren_depth;
  uint *src;
  uint *puVar3;
  int angle_depth;
  int cond_depth;
  
  cond_depth = 0;
  angle_depth = 0;
  paren_depth = depth;
switchD_1042f280_caseD_1:
  if ((g_compile_flags_c8 & 0x8000000) == 0) {
    depth = (int)yylex_cpp();
  }
  else {
    depth = (int)token_next((c1_token_reader *)&g_token_position);
    if ((*(byte *)depth == 6) && ((g_compile_flags_c8 & 0x10000000) == 0)) {
      next_token = token_next((c1_token_reader *)&g_token_position);
      uVar1 = *(uint *)(*(int *)(depth + 8) + 8);
      if ((uVar1 & 0x4000000) == 0) {
        if (((uVar1 & 0x20000) != 0) && (*next_token == 0x44)) {
          parse_template_argument_list_save_tail
                    (next_token,paren_depth,0x10000000,angle_depth,cond_depth,(byte *)depth);
          return;
        }
        (*g_token_source->stream->vtbl->unget)(g_token_source->stream,(char *)next_token);
      }
      else {
        (*g_token_source->stream->vtbl->unget)(g_token_source->stream,(char *)next_token);
        if (g_class_depth < 0) {
          qualifier = (c1_symbol *)0x0;
        }
        else {
          qualifier = g_class_def_stack[g_class_depth].cls;
        }
        tmpl_resolve_template_name_token((c1_u8 **)&depth,qualifier,'\0');
      }
    }
    else if (*(byte *)depth == 0x98) {
      parse_template_argument_list_overload_token
                ((byte *)depth,paren_depth,0x10000000,angle_depth,cond_depth,(byte *)depth);
      return;
    }
  }
  if ((&g_token_static_records)[*(byte *)depth] == 0) {
    if (g_token_arena_index == 0) {
      if (g_pool_default_left < 0x30) {
        pool_reserve((c1xx_pool *)&g_pool_default,0x30);
      }
      g_pool_default_left = g_pool_default_left - 0x30;
      token = (uint *)g_pool_default;
      g_pool_default = g_pool_default + 0x30;
    }
    else {
      a = g_arenas + g_token_arena_index;
      token = (uint *)a->cur;
      puVar3 = (uint *)g_arenas[g_token_arena_index].end;
      a->cur = (c1_u8 *)(token + 0xc);
      if (puVar3 < token + 0xc) {
        arena_grow(a);
      }
    }
    if (token == (uint *)0x0) {
      token = (uint *)0x0;
      this = g_token_save_frame->stream;
    }
    else {
      src = (uint *)depth;
      puVar3 = token;
      for (iVar2 = 0xc; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar3 = *src;
        src = src + 1;
        puVar3 = puVar3 + 1;
      }
      this = g_token_save_frame->stream;
    }
  }
  else {
    this = g_token_save_frame->stream;
    token = (uint *)depth;
  }
  (*this->vtbl->append)(this,(int)token);
  switch(*(undefined1 *)depth) {
  case 0:
  case 5:
  case 0x6d:
  case 0x75:
  case 0x7b:
  case 0x7f:
  case 0xa6:
    goto switchD_1042f280_caseD_0;
  default:
    goto switchD_1042f280_caseD_1;
  case 0x36:
    cond_depth = cond_depth + -1;
    iVar2 = cond_depth;
    break;
  case 0x37:
    if ((paren_depth == 0) && ((g_compile_flags_c8 & 0x8000000) != 0)) {
      return;
    }
    goto switchD_1042f280_caseD_1;
  case 0x3e:
  case 0xbf:
    if (((g_compile_flags_c8 & 0x20000000) != 0) && (paren_depth == 0)) {
      return;
    }
    if ((g_compile_flags_c8 & 0x10000000) != 0) {
      if (angle_depth == 0) {
        return;
      }
      angle_depth = angle_depth + -1;
    }
    goto switchD_1042f280_caseD_1;
  case 0x44:
    if ((g_compile_flags_c8 & 0x10000000) != 0) {
      angle_depth = angle_depth + 1;
    }
    goto switchD_1042f280_caseD_1;
  case 0x56:
    cond_depth = cond_depth + 1;
    goto switchD_1042f280_caseD_1;
  case 0x76:
    paren_depth = paren_depth + 1;
    goto switchD_1042f280_caseD_1;
  case 0x7e:
    paren_depth = paren_depth + -1;
    iVar2 = paren_depth;
  }
  if (iVar2 < 0) {
    return;
  }
  goto switchD_1042f280_caseD_1;
switchD_1042f280_caseD_0:
  return;
}

