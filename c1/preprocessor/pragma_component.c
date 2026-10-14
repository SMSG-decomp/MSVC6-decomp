void pragma_component(void)

{
  byte bVar1;
  c1_type *pcVar2;
  c1_token *pcVar3;
  int iVar4;
  c1_type *pcVar5;
  byte bVar6;
  char *pcVar7;
  bool bVar8;
  c1_emitter_suspend *suspend;
  
  pcVar3 = token_next(&g_token_position);
  if (pcVar3->code == '7') {
    pcVar3 = pragma_check_on_off();
    if (pcVar3 != (c1_token *)0x0) {
      bVar6 = (pcVar3->value).spec.words.storage & 1;
      pcVar3 = token_next(&g_token_position);
      suspend = g_emitter_suspend;
      if (pcVar3->code == '7') {
        pcVar3 = pragma_warn_expected_token('\x06');
        if (pcVar3 != (c1_token *)0x0) {
          pcVar7 = "references";
          pcVar2 = ((pcVar3->value).node)->type;
          pcVar5 = pcVar2;
          do {
            bVar1 = (byte)pcVar5->code;
            bVar8 = bVar1 < (byte)*pcVar7;
            if (bVar1 != *pcVar7) {
LAB_1062aba8:
              iVar4 = (1 - (uint)bVar8) - (uint)(bVar8 != 0);
              goto LAB_1062ab71;
            }
            if (bVar1 == 0) break;
            bVar1 = *(byte *)((int)&pcVar5->code + 1);
            bVar8 = bVar1 < (byte)pcVar7[1];
            if (bVar1 != pcVar7[1]) goto LAB_1062aba8;
            pcVar5 = (c1_type *)&pcVar5->flags;
            pcVar7 = pcVar7 + 2;
          } while (bVar1 != 0);
          iVar4 = 0;
LAB_1062ab71:
          if (iVar4 == 0) {
            pcVar3 = token_next(&g_token_position);
            if (pcVar3->code == '7') {
              g_emitter_suspend->browse_on = bVar6;
              pragma_parse_list(pragma_component_set_name_references);
              pragma_warn_expected_token('~');
              return;
            }
            if (pcVar3->code == '~') {
              if (bVar6 != 0) {
                g_compile_flags_cc = g_compile_flags_cc & 0xffff7fff;
                return;
              }
              g_compile_flags_cc = g_compile_flags_cc | 0x8000;
              return;
            }
            goto LAB_1062ab8b;
          }
          (*g_token_source->stream->vtbl->unget)(g_token_source->stream,pcVar3);
          pragma_warn_expected_token('~');
          diag_warning(1,0xb0,pcVar2);
          pragma_skip_to_dash(pcVar3);
        }
      }
      else {
        if (pcVar3->code != '~') {
LAB_1062ab8b:
          (*g_token_source->stream->vtbl->unget)(g_token_source->stream,pcVar3);
          pragma_warn_expected_token('~');
          return;
        }
        if ((g_class_depth != -1) || (g_current_function != (c1_symbol *)0x0)) {
          diag_warning(1,0xb1);
          return;
        }
        if (g_emitter_suspend->active != bVar6) {
          if (bVar6 == 0) {
            if (g_browse_file != (char *)0x0) {
              (*g_il_emitter->vtbl->end_module)();
            }
            il_emitter_suspend_enter((char *)suspend);
            return;
          }
          if (g_browse_file == (char *)0x0) {
            diag_warning(1,0xaf);
            return;
          }
          iVar4 = g_emitter_suspend->depth + -1;
          g_emitter_suspend->depth = iVar4;
          if (iVar4 == 0) {
            g_il_emitter = suspend->saved;
            suspend->active = '\x01';
          }
          if (g_browse_file != (char *)0x0) {
            (*g_il_emitter->vtbl->begin_module)();
            return;
          }
        }
      }
    }
  }
  else if (pcVar3->code != '~') {
    (*g_token_source->stream->vtbl->unget)(g_token_source->stream,pcVar3);
    pragma_warn_expected_token('7');
    return;
  }
  return;
}

