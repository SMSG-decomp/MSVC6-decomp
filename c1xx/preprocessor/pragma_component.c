void __cdecl pragma_component(void)

{
  byte bVar1;
  byte *pbVar2;
  c1xx_emitter_suspend *state;
  byte *pbVar3;
  c1_u8 *pcVar4;
  byte *pbVar5;
  int iVar6;
  byte bVar7;
  char *pcVar8;
  bool bVar9;
  
  pbVar3 = token_next((c1_token_reader *)&g_token_position);
  if (*pbVar3 == 0x37) {
    pcVar4 = pragma_check_on_off();
    if (pcVar4 != (c1_u8 *)0x0) {
      bVar7 = pcVar4[8] & 1;
      pbVar3 = token_next((c1_token_reader *)&g_token_position);
      state = g_emitter_suspend;
      if (*pbVar3 == 0x37) {
        pbVar3 = pragma_warn_expected_token('\x06');
        if (pbVar3 != (byte *)0x0) {
          pcVar8 = "references";
          pbVar2 = *(byte **)(*(int *)(pbVar3 + 8) + 4);
          pbVar5 = pbVar2;
          do {
            bVar1 = *pbVar5;
            bVar9 = bVar1 < (byte)*pcVar8;
            if (bVar1 != *pcVar8) {
LAB_1045ec8e:
              iVar6 = (1 - (uint)bVar9) - (uint)(bVar9 != 0);
              goto LAB_104553e8;
            }
            if (bVar1 == 0) break;
            bVar1 = pbVar5[1];
            bVar9 = bVar1 < (byte)pcVar8[1];
            if (bVar1 != pcVar8[1]) goto LAB_1045ec8e;
            pbVar5 = pbVar5 + 2;
            pcVar8 = pcVar8 + 2;
          } while (bVar1 != 0);
          iVar6 = 0;
LAB_104553e8:
          if (iVar6 == 0) {
            pbVar3 = token_next((c1_token_reader *)&g_token_position);
            if (*pbVar3 == 0x37) {
              g_emitter_suspend->references = bVar7;
              pragma_parse_list(pragma_component_set_name_references);
              pragma_warn_expected_token('~');
              return;
            }
            if (*pbVar3 == 0x7e) {
              if (bVar7 != 0) {
                g_compile_flags_cc = g_compile_flags_cc & 0xffff7fff;
                return;
              }
              g_compile_flags_cc = g_compile_flags_cc | 0x8000;
              return;
            }
            goto LAB_1045ec9d;
          }
          (*g_token_source->stream->vtbl->unget)(g_token_source->stream,(char *)pbVar3);
          pragma_warn_expected_token('~');
          diag_warning(1,0xb0,pbVar2);
          pragma_skip_to_dash(pbVar3);
        }
      }
      else {
        if (*pbVar3 != 0x7e) {
LAB_1045ec9d:
          (*g_token_source->stream->vtbl->unget)(g_token_source->stream,(char *)pbVar3);
          pragma_warn_expected_token('~');
          return;
        }
        if ((g_class_depth != -1) || (g_current_function != (c1_symbol *)0x0)) {
          diag_warning(1,0xb1);
          return;
        }
        if (g_emitter_suspend->enabled != bVar7) {
          if (bVar7 == 0) {
            if (g_browse_file != (char *)0x0) {
              (*g_il_emitter->vtbl->end_module)();
            }
            il_emitter_suspend_enter((char *)state);
            return;
          }
          if (g_browse_file == (char *)0x0) {
            diag_warning(1,0xaf);
            return;
          }
          iVar6 = g_emitter_suspend->depth + -1;
          g_emitter_suspend->depth = iVar6;
          if (iVar6 == 0) {
            g_il_emitter = state->saved;
            state->enabled = '\x01';
          }
          if (g_browse_file != (char *)0x0) {
            (*g_il_emitter->vtbl->begin_module)();
            return;
          }
        }
      }
    }
  }
  else if (*pbVar3 != 0x7e) {
    (*g_token_source->stream->vtbl->unget)(g_token_source->stream,(char *)pbVar3);
    pragma_warn_expected_token('7');
    return;
  }
  return;
}

