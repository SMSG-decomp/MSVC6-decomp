void __cdecl decl_parse_declspec(c1_specifier_words *words)

{
  byte bVar1;
  fe_name *pfVar2;
  c1_node *s;
  c1_u8 cVar3;
  c1_token *pcVar4;
  char *pcVar5;
  int iVar6;
  c1_node *pcVar7;
  int *value;
  fe_name *name;
  int unaff_EDI;
  bool bVar8;
  int arg_kind;
  
  pcVar4 = token_next(&g_token_position);
  if (pcVar4->code != 0x76) {
    diag_error(0x36,(uint)pcVar4->code);
    (*g_token_source->stream->vtbl->unget)(g_token_source->stream,pcVar4);
    words->storage = words->storage | 8;
    return;
  }
  pcVar4 = token_next(&g_token_position);
  cVar3 = pcVar4->code;
  if (cVar3 == '~') {
    return;
  }
  do {
    if (cVar3 != '\x06') {
      diag_error(0x3b,0x4c,(uint)pcVar4->code);
      words->storage = words->storage | 8;
      iVar6 = 1;
      do {
        switch(pcVar4->code) {
        case 'm':
        case '\x7f':
          (*g_token_source->stream->vtbl->unget)(g_token_source->stream,pcVar4);
          return;
        case 'v':
          iVar6 = iVar6 + 1;
          pcVar4 = token_next(&g_token_position);
          break;
        case '~':
          iVar6 = iVar6 + -1;
          if (iVar6 == 0) {
            return;
          }
        default:
          pcVar4 = token_next(&g_token_position);
        }
      } while( true );
    }
    pfVar2 = (pcVar4->value).name;
    if ((pfVar2->flags & 0x800000) == 0) {
      diag_error(0x1e5,pfVar2);
    }
    else if ((pfVar2->flags & 0x10000) == 0) {
      bVar1 = pfVar2->token_kind;
      if (g_declspec_attributes[bVar1].kind == 2) {
        decl_specifiers_merge(words,(byte)g_declspec_attributes[bVar1].value,'\x01',unaff_EDI);
      }
      else if ((char)g_declspec_attributes[bVar1].has_argument == '\0') {
        decl_specifiers_merge(words,0,(char)g_declspec_attributes[bVar1].kind,unaff_EDI);
      }
      else if (g_declspec_attributes[bVar1].kind == 8) {
        pcVar4 = token_next(&g_token_position);
        if (pcVar4->code == 0x76) {
          pcVar4 = token_next(&g_token_position);
          if (pcVar4->code == 7) {
            s = (pcVar4->value).node;
            pcVar5 = "_DATA";
            pcVar7 = s;
            do {
              bVar1 = pcVar7->op;
              bVar8 = bVar1 < (byte)*pcVar5;
              if (bVar1 != *pcVar5) {
LAB_10626f81:
                iVar6 = (1 - (uint)bVar8) - (uint)(bVar8 != 0);
                goto LAB_10626f27;
              }
              if (bVar1 == 0) break;
              bVar1 = pcVar7->kind;
              bVar8 = bVar1 < (byte)pcVar5[1];
              if (bVar1 != pcVar5[1]) goto LAB_10626f81;
              pcVar7 = (c1_node *)&pcVar7->flags;
              pcVar5 = pcVar5 + 2;
            } while (bVar1 != 0);
            iVar6 = 0;
LAB_10626f27:
            if (iVar6 == 0) {
              value = g_data_seg_name;
              if (g_data_seg_name == (void *)0x0) {
                value = g_default_data_segment;
              }
            }
            else {
              pcVar5 = "_CODE";
              pcVar7 = s;
              do {
                bVar1 = pcVar7->op;
                bVar8 = bVar1 < (byte)*pcVar5;
                if (bVar1 != *pcVar5) {
LAB_10626fd4:
                  iVar6 = (1 - (uint)bVar8) - (uint)(bVar8 != 0);
                  goto LAB_10626fb1;
                }
                if (bVar1 == 0) break;
                bVar1 = pcVar7->kind;
                bVar8 = bVar1 < (byte)pcVar5[1];
                if (bVar1 != pcVar5[1]) goto LAB_10626fd4;
                pcVar7 = (c1_node *)&pcVar7->flags;
                pcVar5 = pcVar5 + 2;
              } while (bVar1 != 0);
              iVar6 = 0;
LAB_10626fb1:
              if (iVar6 == 0) {
                if ((g_current_function == (c1_symbol *)0x0) ||
                   ((g_current_function->flags23 & 1) == 0)) {
                  value = g_code_seg_name;
                  if (g_code_seg_name == (void *)0x0) {
                    value = g_default_code_segment;
                  }
                }
                else {
                  value = sym_segment_record(g_current_function);
                }
              }
              else {
                name = name_intern((char *)s);
                value = scope_lookup_segment(g_current_scope,(int)name);
                if (value == (int *)0x0) {
                  diag_error(0x155,s);
                  words->storage = words->storage | 8;
                }
              }
            }
            decl_specifiers_merge(words,0,'\b',(int)value);
            pcVar4 = token_next(&g_token_position);
            if (pcVar4->code != 0x7e) {
              diag_error(0x3b,0x73,g_token_spelling[pcVar4->code]);
              words->storage = words->storage | 8;
            }
            goto LAB_106103d2;
          }
          pcVar5 = (char *)(uint)pcVar4->code;
          arg_kind = 0x4c;
        }
        else {
          pcVar5 = g_token_spelling[pcVar4->code];
          arg_kind = 0x73;
        }
        diag_error(0x3b,arg_kind,pcVar5);
        words->storage = words->storage | 8;
        parse_skip_to_token_in_set(pcVar4,0x7e,1);
      }
    }
    else {
      decl_specifiers_merge(words,0,pfVar2->token_kind,unaff_EDI);
    }
LAB_106103d2:
    pcVar4 = token_next(&g_token_position);
    cVar3 = pcVar4->code;
    if (cVar3 == '~') {
      return;
    }
  } while( true );
}

