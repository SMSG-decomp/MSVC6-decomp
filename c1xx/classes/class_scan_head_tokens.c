c1_u8 * __cdecl class_scan_head_tokens(ushort key_code,c1_u8 *spec)

{
  byte *pbVar1;
  fe_name *name;
  c1_u8 *pcVar2;
  bool bVar3;
  c1_u8 cVar4;
  byte bVar5;
  int *piVar6;
  char *pcVar7;
  c1_u8 *pcVar8;
  c1_symbol *pcVar9;
  c1_arena *a;
  int iVar10;
  uint uVar11;
  c1xx_token_stream *token_stream;
  c1_u8 *unused_edx;
  uint extraout_EDX;
  uint extraout_EDX_00;
  uint edx;
  c1xx_token_stream_vtbl *pcVar12;
  uint extraout_EDX_01;
  uint extraout_EDX_02;
  undefined4 edx_00;
  byte *pbVar13;
  int *head;
  byte *local_4;
  
  piVar6 = arena_alloc(g_arenas + 5,0x34);
  head = (int *)0x0;
  if (piVar6 != (int *)0x0) {
    pbVar1 = (byte *)(piVar6 + 4);
    piVar6[10] = (int)spec;
    *piVar6 = 0;
    piVar6[1] = 0;
    piVar6[2] = 0;
    *(ushort *)(piVar6 + 3) = key_code;
    *(undefined2 *)((int)piVar6 + 0xe) = 0;
    *pbVar1 = *pbVar1 & 0xf8;
    pbVar13 = pbVar1;
    for (iVar10 = 6; iVar10 != 0; iVar10 = iVar10 + -1) {
      pbVar13[0] = 0;
      pbVar13[1] = 0;
      pbVar13[2] = 0;
      pbVar13[3] = 0;
      pbVar13 = pbVar13 + 4;
    }
    *pbVar1 = *pbVar1 & 7 ^ *pbVar1;
    piVar6[0xb] = 0;
    *(undefined1 *)(piVar6 + 0xc) = 1;
    head = piVar6;
  }
  g_class_vtordisp_off = '\0';
  if (((g_compile_flags_c8 & 0x10000000) == 0) ||
     ((((key_code & 0x20f) != 0x201 && ((key_code & 0xfff) != 0x802)) &&
      ((key_code & 0xfff) != 0x801)))) {
    bVar3 = false;
  }
  else {
    bVar3 = true;
  }
  g_compile_flags_c8 = g_compile_flags_c8 & 0xff8fffff;
  local_4 = token_next((c1_token_reader *)&g_token_position);
  uVar11 = (uint)*local_4;
  bVar5 = g_token_class[uVar11];
  while (bVar5 < 0xc0) {
    edx = (uint)(&switchD_10433c81::switchdataD_10437858)[bVar5];
    switch(bVar5) {
    case 0:
      diag_fatal_simple(4);
    default:
      goto switchD_10433c81_caseD_1;
    case 6:
      name = *(fe_name **)(local_4 + 8);
      pcVar7 = lex_peek_token((uint *)&g_token_position);
      if (bVar3) {
        switch(*pcVar7) {
        case '4':
        case '7':
        case '>':
        case -0x41:
          pcVar9 = tmpl_declare_type_parameter(name);
          if (g_token_arena_index == 0) {
            pcVar8 = pool_alloc_raw(&g_pool_default,0x30);
          }
          else {
            pcVar8 = arena_alloc(g_arenas + g_token_arena_index,0x30);
          }
          if (pcVar8 == (c1_u8 *)0x0) {
            return (c1_u8 *)0x0;
          }
          *(c1_symbol **)(pcVar8 + 8) = pcVar9;
          *pcVar8 = 0xe5;
          return pcVar8;
        default:
          bVar3 = false;
        }
      }
      if ((*pcVar7 == 'D') && ((name->flags & 0x4020000) != 0)) {
        tmpl_resolve_template_name_token(&local_4,(c1_symbol *)0x0,'\0');
      }
      bVar5 = class_head_take_name(head,local_4);
      edx = extraout_EDX_00;
      goto joined_r0x10433c20;
    case 0x34:
    case 0x37:
    case 0xbf:
switchD_10433c81_caseD_34:
      if (bVar3) {
        pcVar9 = tmpl_declare_type_parameter(g_name_unnamed);
        (*g_token_source->stream->vtbl->unget)(g_token_source->stream,(char *)local_4);
        if (g_token_arena_index == 0) {
          if (g_pool_default_left < 0x30) {
            pool_reserve((c1xx_pool *)&g_pool_default,0x30);
          }
          g_pool_default_left = g_pool_default_left - 0x30;
          pcVar8 = g_pool_default;
          g_pool_default = g_pool_default + 0x30;
        }
        else {
          a = g_arenas + g_token_arena_index;
          pcVar8 = a->cur;
          pcVar2 = g_arenas[g_token_arena_index].end;
          a->cur = pcVar8 + 0x30;
          if (pcVar2 < pcVar8 + 0x30) {
            arena_grow(a);
          }
        }
        if (pcVar8 == (c1_u8 *)0x0) {
          return (c1_u8 *)0x0;
        }
        *(c1_symbol **)(pcVar8 + 8) = pcVar9;
        *pcVar8 = 0xe5;
        return pcVar8;
      }
    case 0x7f:
switchD_10433c81_caseD_7f:
      token_stream = g_token_source->stream;
      pcVar12 = token_stream->vtbl;
      goto LAB_10433d2c;
    case 0x36:
    case 0x75:
      if (g_paren_depth < 1) {
        pcVar8 = parse_check_missing_token(head,edx,(char *)local_4);
        return pcVar8;
      }
      *(undefined1 *)(head + 0xc) = 0;
      (*g_token_source->stream->vtbl->unget)(g_token_source->stream,(char *)local_4);
      pcVar8 = class_parse_head(head,local_4,edx_00);
      return pcVar8;
    case 0x7c:
      if (*local_4 == 0x3e) goto switchD_10433c81_caseD_34;
      goto switchD_10433c81_caseD_7f;
    case 0x95:
      (*g_token_source->stream->vtbl->unget)(g_token_source->stream,(char *)local_4);
      bVar5 = class_head_compose_qualified_name(head,unused_edx);
      edx = extraout_EDX;
      goto joined_r0x10433c20;
    case 0x96:
      bVar5 = class_head_take_qualified_name(head,local_4);
      edx = extraout_EDX_02;
joined_r0x10433c20:
      if (bVar5 == 0) goto LAB_10433d34;
      break;
    case 0xa8:
      g_class_vtordisp_off = '\x01';
      break;
    case 0xb1:
      if (uVar11 == 0xb2) {
        g_compile_flags_c8 = g_compile_flags_c8 & 0xff9fffff | 0x100000;
      }
      else if (uVar11 == 0xb3) {
        g_compile_flags_c8 = g_compile_flags_c8 & 0xffafffff | 0x200000;
      }
      else {
        if (uVar11 != 0xb4) goto LAB_10433d34;
        g_compile_flags_c8 = g_compile_flags_c8 & 0xffbfffff | 0x300000;
      }
      break;
    case 0xba:
      cVar4 = decl_tag_parse_declspec(head);
      if (cVar4 == '\0') goto LAB_10433bf7;
    }
    local_4 = token_next((c1_token_reader *)&g_token_position);
    uVar11 = (uint)*local_4;
    bVar5 = g_token_class[uVar11];
  }
switchD_10433c81_caseD_1:
  *(undefined1 *)(head + 0xc) = 0;
LAB_10433bf7:
  token_stream = g_token_source->stream;
  pcVar12 = token_stream->vtbl;
LAB_10433d2c:
  (*pcVar12->unget)(token_stream,(char *)local_4);
  edx = extraout_EDX_01;
LAB_10433d34:
  pcVar8 = class_parse_head(head,local_4,edx);
  return pcVar8;
}

