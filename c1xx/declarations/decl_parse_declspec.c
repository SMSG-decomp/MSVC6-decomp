void __cdecl decl_parse_declspec(byte *spec,int value)

{
  c1_guid *guid;
  c1_guid *pcVar1;
  byte bVar2;
  bool bVar3;
  byte *pbVar4;
  c1xx_token *pcVar5;
  c1_arena *a;
  byte *pbVar6;
  c1_symbol *value_00;
  void *pvVar7;
  int iVar8;
  char *pcVar9;
  undefined4 uVar10;
  
  pbVar4 = token_next((c1_token_reader *)&g_token_position);
  if (*pbVar4 != 0x76) {
    diag_error(0x36,(uint)*pbVar4);
    (*g_token_source->stream->vtbl->unget)(g_token_source->stream,(char *)pbVar4);
    *spec = *spec | 8;
    return;
  }
  pcVar5 = (c1xx_token *)token_next((c1_token_reader *)&g_token_position);
  bVar2 = pcVar5->code;
  if (bVar2 == 0x7e) {
    return;
  }
  do {
    if (bVar2 != 6) {
      diag_error(0x3b,0x4c,(uint)pcVar5->code);
      *spec = *spec | 8;
      iVar8 = 1;
      do {
        switch(pcVar5->code) {
        case 'm':
        case '\x7f':
          (*g_token_source->stream->vtbl->unget)(g_token_source->stream,(char *)pcVar5);
          return;
        case 'v':
          iVar8 = iVar8 + 1;
          pcVar5 = (c1xx_token *)token_next((c1_token_reader *)&g_token_position);
          break;
        case '~':
          iVar8 = iVar8 + -1;
          if (iVar8 == 0) {
            return;
          }
        default:
          pcVar5 = (c1xx_token *)token_next((c1_token_reader *)&g_token_position);
        }
      } while( true );
    }
    pvVar7 = pcVar5->value;
    if ((*(uint *)((int)pvVar7 + 8) & 0x800000) == 0) {
      diag_error(0x1e5,pvVar7);
    }
    else if ((*(uint *)((int)pvVar7 + 8) & 0x10000) == 0) {
      bVar2 = *(byte *)((int)pvVar7 + 0x10);
      if (g_declspec_attribute_table[bVar2].kind == 2) {
        decl_specifiers_merge(spec,g_declspec_attribute_table[bVar2].storage_class,'\x01',value);
      }
      else if (g_declspec_attribute_table[bVar2].has_arguments == '\0') {
        decl_specifiers_merge(spec,0,(char)g_declspec_attribute_table[bVar2].kind,value);
      }
      else {
        switch(g_declspec_attribute_table[bVar2].kind) {
        case 8:
          pcVar5 = (c1xx_token *)token_next((c1_token_reader *)&g_token_position);
          if (pcVar5->code == 0x76) {
            pcVar5 = (c1xx_token *)token_next((c1_token_reader *)&g_token_position);
            pcVar9 = (char *)(uint)pcVar5->code;
            if (pcVar5->code == 7) {
              pbVar4 = pcVar5->value;
              pcVar9 = "_DATA";
              pbVar6 = pbVar4;
              do {
                bVar2 = *pbVar6;
                bVar3 = bVar2 < (byte)*pcVar9;
                if (bVar2 != *pcVar9) {
LAB_1045843b:
                  iVar8 = (1 - (uint)bVar3) - (uint)(bVar3 != 0);
                  goto LAB_104583e1;
                }
                if (bVar2 == 0) break;
                bVar2 = pbVar6[1];
                bVar3 = bVar2 < (byte)pcVar9[1];
                if (bVar2 != pcVar9[1]) goto LAB_1045843b;
                pbVar6 = pbVar6 + 2;
                pcVar9 = pcVar9 + 2;
              } while (bVar2 != 0);
              iVar8 = 0;
LAB_104583e1:
              if (iVar8 == 0) {
                value_00 = g_data_seg_name;
                if (g_data_seg_name == (void *)0x0) {
                  value_00 = g_default_data_segment;
                }
              }
              else {
                pcVar9 = "_CODE";
                pbVar6 = pbVar4;
                do {
                  bVar2 = *pbVar6;
                  bVar3 = bVar2 < (byte)*pcVar9;
                  if (bVar2 != *pcVar9) {
LAB_1045848e:
                    iVar8 = (1 - (uint)bVar3) - (uint)(bVar3 != 0);
                    goto LAB_1045846b;
                  }
                  if (bVar2 == 0) break;
                  bVar2 = pbVar6[1];
                  bVar3 = bVar2 < (byte)pcVar9[1];
                  if (bVar2 != pcVar9[1]) goto LAB_1045848e;
                  pbVar6 = pbVar6 + 2;
                  pcVar9 = pcVar9 + 2;
                } while (bVar2 != 0);
                iVar8 = 0;
LAB_1045846b:
                if (iVar8 == 0) {
                  if ((g_current_function == (c1_symbol *)0x0) ||
                     ((g_current_function->flags23 & 1) == 0)) {
                    value_00 = g_code_seg_name;
                    if (g_code_seg_name == (void *)0x0) {
                      value_00 = g_default_code_segment;
                    }
                  }
                  else {
                    value_00 = sym_segment_record(g_current_function);
                  }
                }
                else {
                  pvVar7 = name_intern((char *)pbVar4);
                  value_00 = (c1_symbol *)scope_lookup_segment(g_current_scope,pvVar7);
                  if (value_00 == (c1_symbol *)0x0) {
                    diag_error(0x155,pbVar4);
                    *spec = *spec | 8;
                  }
                }
              }
              decl_specifiers_merge(spec,0,'\b',(int)value_00);
              pbVar4 = token_next((c1_token_reader *)&g_token_position);
              if (*pbVar4 != 0x7e) {
                pcVar9 = g_token_spelling[*pbVar4];
LAB_10458424:
                diag_error(0x3b,0x73,pcVar9);
                *spec = *spec | 8;
              }
              break;
            }
LAB_10458508:
            uVar10 = 0x4c;
          }
          else {
            pcVar9 = g_token_spelling[pcVar5->code];
            uVar10 = 0x73;
          }
LAB_10458380:
          diag_error(0x3b,uVar10,pcVar9);
          *spec = *spec | 8;
          parse_skip_tokens_to_one_of(pcVar5,0x7e,1);
          break;
        case 0xb:
          decl_parse_property_declspec(spec);
          break;
        case 0xc:
          pcVar5 = (c1xx_token *)token_next((c1_token_reader *)&g_token_position);
          if (pcVar5->code != 0x76) {
            pcVar9 = g_token_spelling[pcVar5->code];
            uVar10 = 0x73;
            goto LAB_10458380;
          }
          pcVar5 = (c1xx_token *)token_next((c1_token_reader *)&g_token_position);
          pcVar9 = (char *)(uint)pcVar5->code;
          if (pcVar5->code != 7) goto LAB_10458508;
          pcVar9 = pcVar5->value;
          if ((((g_block_depth == '\0') || (-1 < g_class_depth)) ||
              ((g_compile_flags_c8 & 0x10000000) != 0)) ||
             (((((g_compile_flags_c8 & 0x40000000) != 0 && ((g_compile_flags_cc & 8) == 0)) &&
               ((g_compile_flags_c4 & 0x200) == 0)) || ((g_compile_flags_cc & 0x50) != 0)))) {
            iVar8 = 0;
          }
          else {
            iVar8 = 4;
          }
          a = g_arenas + iVar8;
          guid = (c1_guid *)a->cur;
          pcVar1 = (c1_guid *)g_arenas[iVar8].end;
          a->cur = (c1_u8 *)(guid + 1);
          if (pcVar1 < guid + 1) {
            arena_grow(a);
          }
          bVar3 = guid_parse_string(pcVar9,guid);
          if (bVar3) {
            decl_specifiers_merge(spec,0,'\f',(int)guid);
          }
          else {
            diag_error(0x30a);
          }
          pbVar4 = token_next((c1_token_reader *)&g_token_position);
          bVar2 = *pbVar4;
joined_r0x1045860a:
          if (bVar2 != 0x7e) {
            pcVar9 = g_token_spelling[bVar2];
            goto LAB_10458424;
          }
          break;
        case 0x11:
          if ((g_compile_flags_cc & 0x800000) != 0) {
            pcVar5 = (c1xx_token *)token_next((c1_token_reader *)&g_token_position);
            if (pcVar5->code == 0x76) {
              pcVar5 = (c1xx_token *)token_next((c1_token_reader *)&g_token_position);
              pcVar9 = (char *)(uint)pcVar5->code;
              if (pcVar5->code == 0x65) {
                decl_specifiers_merge(spec,0,'\x11',pcVar5->value2);
                pbVar4 = token_next((c1_token_reader *)&g_token_position);
                bVar2 = *pbVar4;
                goto joined_r0x1045860a;
              }
              goto LAB_10458508;
            }
            pcVar9 = g_token_spelling[pcVar5->code];
            uVar10 = 0x73;
            goto LAB_10458380;
          }
          diag_error(0x14a);
          *spec = *spec | 8;
          parse_skip_tokens_to_one_of(pcVar5,0x7e,1);
        }
      }
    }
    else {
      decl_specifiers_merge(spec,0,*(char *)((int)pvVar7 + 0x10),value);
    }
    pcVar5 = (c1xx_token *)token_next((c1_token_reader *)&g_token_position);
    bVar2 = pcVar5->code;
    if (bVar2 == 0x7e) {
      return;
    }
  } while( true );
}

