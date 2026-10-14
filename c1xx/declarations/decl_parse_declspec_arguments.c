void decl_parse_declspec_arguments(byte *spec)

{
  byte bVar1;
  c1_guid *guid;
  c1_guid *pcVar2;
  c1_arena *a;
  c1xx_token *pcVar3;
  byte *pbVar4;
  byte *pbVar5;
  c1_symbol *value;
  void *pvVar6;
  int iVar7;
  char *pcVar8;
  bool bVar9;
  int unaff_retaddr;
  undefined4 uVar10;
  
code_r0x1045835f:
  pcVar3 = (c1xx_token *)token_next((c1_token_reader *)&g_token_position);
  if (pcVar3->code != 0x76) {
    pcVar8 = g_token_spelling[pcVar3->code];
    uVar10 = 0x73;
    goto LAB_10458380;
  }
  pcVar3 = (c1xx_token *)token_next((c1_token_reader *)&g_token_position);
  pcVar8 = (char *)(uint)pcVar3->code;
  if (pcVar3->code != 7) goto LAB_10458508;
  pbVar5 = pcVar3->value;
  pcVar8 = "_DATA";
  pbVar4 = pbVar5;
  do {
    bVar1 = *pbVar4;
    bVar9 = bVar1 < (byte)*pcVar8;
    if (bVar1 != *pcVar8) {
LAB_1045843b:
      iVar7 = (1 - (uint)bVar9) - (uint)(bVar9 != 0);
      goto LAB_104583e1;
    }
    if (bVar1 == 0) break;
    bVar1 = pbVar4[1];
    bVar9 = bVar1 < (byte)pcVar8[1];
    if (bVar1 != pcVar8[1]) goto LAB_1045843b;
    pbVar4 = pbVar4 + 2;
    pcVar8 = pcVar8 + 2;
  } while (bVar1 != 0);
  iVar7 = 0;
LAB_104583e1:
  if (iVar7 == 0) {
    value = g_data_seg_name;
    if (g_data_seg_name == (void *)0x0) {
      value = g_default_data_segment;
    }
  }
  else {
    pcVar8 = "_CODE";
    pbVar4 = pbVar5;
    do {
      bVar1 = *pbVar4;
      bVar9 = bVar1 < (byte)*pcVar8;
      if (bVar1 != *pcVar8) {
LAB_1045848e:
        iVar7 = (1 - (uint)bVar9) - (uint)(bVar9 != 0);
        goto LAB_1045846b;
      }
      if (bVar1 == 0) break;
      bVar1 = pbVar4[1];
      bVar9 = bVar1 < (byte)pcVar8[1];
      if (bVar1 != pcVar8[1]) goto LAB_1045848e;
      pbVar4 = pbVar4 + 2;
      pcVar8 = pcVar8 + 2;
    } while (bVar1 != 0);
    iVar7 = 0;
LAB_1045846b:
    if (iVar7 == 0) {
      if ((g_current_function == (c1_symbol *)0x0) || ((g_current_function->flags23 & 1) == 0)) {
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
      pvVar6 = name_intern((char *)pbVar5);
      value = (c1_symbol *)scope_lookup_segment(g_current_scope,pvVar6);
      if (value == (c1_symbol *)0x0) {
        diag_error(0x155,pbVar5);
        *spec = *spec | 8;
      }
    }
  }
  decl_specifiers_merge(spec,0,'\b',(int)value);
  pbVar5 = token_next((c1_token_reader *)&g_token_position);
  if (*pbVar5 == 0x7e) goto switchD_1044df5f_caseD_9;
  pcVar8 = g_token_spelling[*pbVar5];
LAB_10458424:
  diag_error(0x3b,0x73,pcVar8);
  *spec = *spec | 8;
switchD_1044df5f_caseD_9:
  pcVar3 = (c1xx_token *)token_next((c1_token_reader *)&g_token_position);
  if (pcVar3->code == '~') {
    return;
  }
  if (pcVar3->code != '\x06') {
    diag_error(0x3b,0x4c,(uint)pcVar3->code);
    *spec = *spec | 8;
    iVar7 = 1;
    do {
      switch(pcVar3->code) {
      case 'm':
      case '\x7f':
        (*g_token_source->stream->vtbl->unget)(g_token_source->stream,(char *)pcVar3);
        return;
      case 'v':
        iVar7 = iVar7 + 1;
        pcVar3 = (c1xx_token *)token_next((c1_token_reader *)&g_token_position);
        break;
      case '~':
        iVar7 = iVar7 + -1;
        if (iVar7 == 0) {
          return;
        }
      default:
        pcVar3 = (c1xx_token *)token_next((c1_token_reader *)&g_token_position);
      }
    } while( true );
  }
  pvVar6 = pcVar3->value;
  if ((*(uint *)((int)pvVar6 + 8) & 0x800000) == 0) {
    diag_error(0x1e5,pvVar6);
    goto switchD_1044df5f_caseD_9;
  }
  if ((*(uint *)((int)pvVar6 + 8) & 0x10000) != 0) {
    decl_specifiers_merge(spec,0,*(char *)((int)pvVar6 + 0x10),unaff_retaddr);
    goto switchD_1044df5f_caseD_9;
  }
  bVar1 = *(byte *)((int)pvVar6 + 0x10);
  if (g_declspec_attribute_table[bVar1].kind == 2) {
    decl_specifiers_merge(spec,g_declspec_attribute_table[bVar1].storage_class,'\x01',unaff_retaddr)
    ;
    goto switchD_1044df5f_caseD_9;
  }
  if (g_declspec_attribute_table[bVar1].has_arguments == '\0') {
    decl_specifiers_merge(spec,0,(char)g_declspec_attribute_table[bVar1].kind,unaff_retaddr);
    goto switchD_1044df5f_caseD_9;
  }
  switch(g_declspec_attribute_table[bVar1].kind) {
  case 8:
    goto code_r0x1045835f;
  default:
    goto switchD_1044df5f_caseD_9;
  case 0xb:
    decl_parse_property_declspec(spec);
    goto switchD_1044df5f_caseD_9;
  case 0xc:
    break;
  case 0x11:
    if ((g_compile_flags_cc & 0x800000) == 0) {
      diag_error(0x14a);
      *spec = *spec | 8;
      parse_skip_tokens_to_one_of(pcVar3,0x7e,1);
    }
    else {
      pcVar3 = (c1xx_token *)token_next((c1_token_reader *)&g_token_position);
      if (pcVar3->code == 0x76) {
        pcVar3 = (c1xx_token *)token_next((c1_token_reader *)&g_token_position);
        pcVar8 = (char *)(uint)pcVar3->code;
        if (pcVar3->code != 0x65) goto LAB_10458508;
        decl_specifiers_merge(spec,0,'\x11',pcVar3->value2);
        pbVar5 = token_next((c1_token_reader *)&g_token_position);
        bVar1 = *pbVar5;
        goto joined_r0x1045860a;
      }
      pcVar8 = g_token_spelling[pcVar3->code];
      uVar10 = 0x73;
LAB_10458380:
      diag_error(0x3b,uVar10,pcVar8);
      *spec = *spec | 8;
      parse_skip_tokens_to_one_of(pcVar3,0x7e,1);
    }
    goto switchD_1044df5f_caseD_9;
  }
  pcVar3 = (c1xx_token *)token_next((c1_token_reader *)&g_token_position);
  if (pcVar3->code != 0x76) {
    pcVar8 = g_token_spelling[pcVar3->code];
    uVar10 = 0x73;
    goto LAB_10458380;
  }
  pcVar3 = (c1xx_token *)token_next((c1_token_reader *)&g_token_position);
  pcVar8 = (char *)(uint)pcVar3->code;
  if (pcVar3->code != 7) {
LAB_10458508:
    uVar10 = 0x4c;
    goto LAB_10458380;
  }
  pcVar8 = pcVar3->value;
  if (((((g_block_depth == '\0') || (-1 < g_class_depth)) ||
       ((g_compile_flags_c8 & 0x10000000) != 0)) ||
      ((((g_compile_flags_c8 & 0x40000000) != 0 && ((g_compile_flags_cc & 8) == 0)) &&
       ((g_compile_flags_c4 & 0x200) == 0)))) || ((g_compile_flags_cc & 0x50) != 0)) {
    iVar7 = 0;
  }
  else {
    iVar7 = 4;
  }
  a = g_arenas + iVar7;
  guid = (c1_guid *)a->cur;
  pcVar2 = (c1_guid *)g_arenas[iVar7].end;
  a->cur = (c1_u8 *)(guid + 1);
  if (pcVar2 < guid + 1) {
    arena_grow(a);
  }
  bVar9 = guid_parse_string(pcVar8,guid);
  if (bVar9) {
    decl_specifiers_merge(spec,0,'\f',(int)guid);
  }
  else {
    diag_error(0x30a);
  }
  pbVar5 = token_next((c1_token_reader *)&g_token_position);
  bVar1 = *pbVar5;
joined_r0x1045860a:
  if (bVar1 != 0x7e) goto LAB_10458610;
  goto switchD_1044df5f_caseD_9;
LAB_10458610:
  pcVar8 = g_token_spelling[bVar1];
  goto LAB_10458424;
}

