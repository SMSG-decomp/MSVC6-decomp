char __cdecl parse_default_argument_needs_saving(void)

{
  c1_token_source_frame **ppcVar1;
  _func_193 **pp_Var2;
  byte bVar3;
  bool bVar4;
  c1xx_token_stream *pcVar5;
  byte *pbVar6;
  c1_symbol *pcVar7;
  int iVar8;
  int iVar9;
  uint *puVar10;
  void *name;
  uint *puVar11;
  char local_5;
  int local_4;
  
  iVar9 = 0;
  local_4 = 0;
  bVar4 = true;
  local_5 = '\0';
  pcVar5 = arena_alloc(g_arenas + 5,0x38);
  if (pcVar5 == (c1xx_token_stream *)0x0) {
    pcVar5 = (c1xx_token_stream *)0x0;
  }
  else {
    pcVar5 = token_stream_copy(pcVar5,g_token_source->stream);
  }
  token_source_push((c1_token_reader *)&g_token_position,pcVar5,5,0,(void *)0x0,&g_token_position);
switchD_1041cd90_caseD_2:
  do {
LAB_1041cd5c:
    if (iVar9 < 0) goto LAB_1041ce10;
    pbVar6 = token_next((c1_token_reader *)&g_token_position);
    bVar3 = *pbVar6;
    if (g_token_class[bVar3] != 'e') {
      switch((uint)bVar3) {
      case 1:
      case 0xf7:
        iVar9 = -1;
      default:
        goto switchD_1041cd90_caseD_2;
      case 6:
      case 0xd9:
      case 0xe4:
        if (!bVar4) goto switchD_1041cd90_caseD_2;
        if (bVar3 == 6) {
          name = *(void **)(pbVar6 + 8);
        }
        else if (bVar3 == 0xe4) {
          name = (void *)**(undefined4 **)(pbVar6 + 8);
        }
        else {
          name = *(void **)(**(int **)(pbVar6 + 8) + 8);
        }
        if (((-1 < g_class_depth) &&
            (pcVar7 = class_current_member_lookup(name), pcVar7 != (c1_symbol *)0x0)) &&
           ((pcVar7->kind & 0x1f) == 5)) goto switchD_1041cd90_caseD_2;
        local_5 = '\x01';
        break;
      case 0x1e:
      case 0x96:
      case 0x98:
      case 0xa4:
        if (!bVar4) goto switchD_1041cd90_caseD_2;
        local_5 = '\x01';
        break;
      case 0x34:
        bVar4 = true;
        goto switchD_1041cd90_caseD_2;
      case 0x37:
        goto switchD_1041cd90_caseD_37;
      case 0x41:
        local_4 = local_4 + 1;
        goto switchD_1041cd90_caseD_2;
      case 0x76:
        iVar9 = iVar9 + 1;
        goto switchD_1041cd90_caseD_2;
      case 0x7a:
        local_4 = local_4 + -1;
        goto switchD_1041cd90_caseD_2;
      case 0x7e:
        iVar9 = iVar9 + -1;
        goto switchD_1041cd90_caseD_2;
      }
LAB_1041ce10:
      if (g_token_source != (c1_token_source_frame *)0x0) {
        ppcVar1 = &g_token_source->prev;
        g_token_position = g_token_source->position;
        pp_Var2 = &g_token_source->on_pop;
        g_token_source = *ppcVar1;
        if (*pp_Var2 != (_func_193 *)0x0) {
          (**pp_Var2)();
        }
      }
      return local_5;
    }
    g_yylval = (uint)tree_new_constant(*(c1_type **)(pbVar6 + 8),pbVar6 + 0x10,0);
    *pbVar6 = 0xb0;
    puVar10 = &g_yylval;
    puVar11 = (uint *)(pbVar6 + 8);
    for (iVar8 = 10; iVar8 != 0; iVar8 = iVar8 + -1) {
      *puVar11 = *puVar10;
      puVar10 = puVar10 + 1;
      puVar11 = puVar11 + 1;
    }
  } while( true );
switchD_1041cd90_caseD_37:
  if (iVar9 == 0) goto code_r0x1041ce54;
  goto LAB_1041cd5c;
code_r0x1041ce54:
  if (local_4 == 0) {
    bVar4 = false;
  }
  goto switchD_1041cd90_caseD_2;
}

