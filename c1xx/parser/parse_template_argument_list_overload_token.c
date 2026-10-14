void __cdecl
parse_template_argument_list_overload_token
          (byte *overload_token,int paren_depth,uint c8_mask,int angle_depth,int cond_depth,
          byte *token)

{
  byte *pbVar1;
  c1_arena *a;
  c1_symbol *qualifier;
  c1_u8 *pcVar2;
  c1_u32 *token_00;
  int iVar3;
  c1xx_token_stream *this;
  c1_u32 *pcVar4;
  c1_u32 *token_word;
  
  pbVar1 = *(byte **)(*(int *)(overload_token + 8) + 0x10);
  if ((pbVar1 != (byte *)0x0) && ((*pbVar1 & 0x1f) == 0x12)) {
    iVar3 = g_token_save_frame->stream->arena;
    if (iVar3 == 0) {
      pcVar2 = list_copy_with_header(*(int **)(pbVar1 + 0x14),0);
      *(c1_u8 **)(pbVar1 + 0x14) = pcVar2;
    }
    else if (iVar3 == 2) {
      pcVar2 = list_copy_with_header(*(int **)(pbVar1 + 0x14),2);
      *(c1_u8 **)(pbVar1 + 0x14) = pcVar2;
    }
  }
  do {
    if ((&g_token_static_records)[*token] == 0) {
      if (g_token_arena_index == 0) {
        if (g_pool_default_left < 0x30) {
          pool_reserve((c1xx_pool *)&g_pool_default,0x30);
        }
        g_pool_default_left = g_pool_default_left - 0x30;
        token_00 = (c1_u32 *)g_pool_default;
        g_pool_default = g_pool_default + 0x30;
      }
      else {
        a = g_arenas + g_token_arena_index;
        token_00 = (c1_u32 *)a->cur;
        pcVar4 = (c1_u32 *)g_arenas[g_token_arena_index].end;
        a->cur = (c1_u8 *)(token_00 + 0xc);
        if (pcVar4 < token_00 + 0xc) {
          arena_grow(a);
        }
      }
      if (token_00 == (c1_u32 *)0x0) {
        token_00 = (c1_u32 *)0x0;
        this = g_token_save_frame->stream;
      }
      else {
        pcVar4 = (c1_u32 *)token;
        token_word = token_00;
        for (iVar3 = 0xc; iVar3 != 0; iVar3 = iVar3 + -1) {
          *token_word = *pcVar4;
          pcVar4 = pcVar4 + 1;
          token_word = token_word + 1;
        }
        this = g_token_save_frame->stream;
      }
    }
    else {
      this = g_token_save_frame->stream;
      token_00 = (c1_u32 *)token;
    }
    (*this->vtbl->append)(this,(int)token_00);
    switch(*token) {
    case 0:
    case 5:
    case 0x6d:
    case 0x75:
    case 0x7b:
    case 0x7f:
    case 0xa6:
      goto switchD_1042f280_caseD_0;
    case 0x36:
      cond_depth = cond_depth + -1;
      iVar3 = cond_depth;
      goto joined_r0x1042f229;
    case 0x37:
      if ((paren_depth == 0) && ((g_compile_flags_c8 & 0x8000000) != 0)) {
        return;
      }
      break;
    case 0x3e:
    case 0xbf:
      if (((g_compile_flags_c8 & 0x20000000) != 0) && (paren_depth == 0)) {
        return;
      }
      if ((c8_mask & g_compile_flags_c8) != 0) {
        if (angle_depth == 0) {
          return;
        }
        angle_depth = angle_depth + -1;
      }
      break;
    case 0x44:
      if ((g_compile_flags_c8 & c8_mask) != 0) {
        angle_depth = angle_depth + 1;
      }
      break;
    case 0x56:
      cond_depth = cond_depth + 1;
      break;
    case 0x76:
      paren_depth = paren_depth + 1;
      break;
    case 0x7e:
      paren_depth = paren_depth + -1;
      iVar3 = paren_depth;
joined_r0x1042f229:
      if (iVar3 < 0) {
switchD_1042f280_caseD_0:
        return;
      }
    }
    if ((g_compile_flags_c8 & 0x8000000) == 0) {
      token = yylex_cpp();
    }
    else {
      token = token_next((c1_token_reader *)&g_token_position);
      if ((*token == 6) && ((g_compile_flags_c8 & c8_mask) == 0)) {
        pbVar1 = token_next((c1_token_reader *)&g_token_position);
        if ((*(uint *)(*(int *)(token + 8) + 8) & 0x4000000) == 0) {
          if (((*(uint *)(*(int *)(token + 8) + 8) & 0x20000) != 0) && (*pbVar1 == 0x44)) {
            parse_template_argument_list_save_tail
                      (pbVar1,paren_depth,c8_mask,angle_depth,cond_depth,token);
            return;
          }
          (*g_token_source->stream->vtbl->unget)(g_token_source->stream,(char *)pbVar1);
        }
        else {
          (*g_token_source->stream->vtbl->unget)(g_token_source->stream,(char *)pbVar1);
          if (g_class_depth < 0) {
            qualifier = (c1_symbol *)0x0;
          }
          else {
            qualifier = g_class_def_stack[g_class_depth].cls;
          }
          tmpl_resolve_template_name_token(&token,qualifier,'\0');
        }
      }
      else if (*token == 0x98) {
        parse_template_argument_list_overload_token
                  (token,paren_depth,c8_mask,angle_depth,cond_depth,token);
        return;
      }
    }
  } while( true );
}

