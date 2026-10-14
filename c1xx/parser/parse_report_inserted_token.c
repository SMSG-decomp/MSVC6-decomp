void __cdecl parse_report_inserted_token(c1_u8 *lookahead,int terminal)

{
  byte bVar1;
  int iVar2;
  char cVar3;
  
  g_flow_analysis_active = g_flow_analysis_active + 1;
  if (-1 < g_class_depth) {
    g_class_syntax_error_count = g_class_syntax_error_count + 1;
  }
  bVar1 = *lookahead;
  switch((uint)bVar1) {
  case 0:
  case 5:
    diag_fatal_simple(4);
  case 6:
    if (*(int *)(lookahead + 8) != 0) {
      diag_error(0x92,terminal,*(int *)(lookahead + 8));
      return;
    }
    diag_error(0x91,terminal);
    return;
  case 0x1e:
  case 0x1f:
  case 0x24:
  case 0x98:
    break;
  case 0x8e:
    diag_error(0x8f,terminal,(uint)lookahead[8]);
    return;
  case 0x9f:
    if ((terminal == 0x7f) &&
       (iVar2 = *(int *)(**(int **)(*(int *)(lookahead + 8) + 0x14) + 8), *(int *)(iVar2 + 8) != 0))
    {
      diag_error(0x291,iVar2);
      return;
    }
  default:
    diag_error(0x8f,terminal,(uint)bVar1);
    return;
  case 0xd9:
    if (*(int *)(**(int **)(lookahead + 8) + 8) != 0) {
      diag_error(0x92,terminal,*(int *)(**(int **)(lookahead + 8) + 8));
      return;
    }
    diag_error(0x91,terminal);
    return;
  }
  iVar2 = *(int *)(lookahead + 0x24);
  if (iVar2 == 0) {
    if (bVar1 == 0x98) {
      iVar2 = *(int *)(*(int *)(lookahead + 8) + 4);
    }
    else {
      iVar2 = *(int *)(lookahead + 0x20);
    }
    cVar3 = 'T';
  }
  else {
    cVar3 = 'S';
  }
  if ((((terminal == 0x7f) && (bVar1 == 0x98)) &&
      (((g_compile_flags_c4 & 0x20000) == 0 || ((g_compile_flags_c4 & 0x20) != 0)))) &&
     (g_class_depth < 0)) {
    diag_error(199,(int)cVar3,iVar2);
    func_flow_state_drop_kind_d();
    return;
  }
  diag_error(0x90,terminal,(int)cVar3,iVar2);
  func_flow_state_drop_kind_d();
  return;
}

