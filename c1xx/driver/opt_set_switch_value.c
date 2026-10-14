void __cdecl opt_set_switch_value(c1_switch_row *row,char *value,int dup)

{
  c1_switch_letter_row *pcVar1;
  char cVar2;
  c1_vector *v;
  int iVar3;
  long lVar4;
  c1_switch_letter_row *letter;
  char *pcVar5;
  char *pcVar6;
  ulong uVar7;
  uint uVar8;
  
  switch(row->kind) {
  case '\x01':
    *row->variable = '\x01';
    return;
  default:
    return;
  case '\x05':
    *row->variable = '\0';
    return;
  case '\"':
    goto switchD_1044580d_caseD_22;
  case '#':
    cVar2 = *value;
    do {
      if (cVar2 == '\0') {
        return;
      }
      letter = (c1_switch_letter_row *)row->variable;
      iVar3 = letter->letter;
      while (iVar3 != 0) {
        if (cVar2 == (char)letter->letter) {
          if (letter->action == 1) {
            *letter->variable = '\x01';
          }
          else if (letter->action == 5) {
            *letter->variable = '\0';
          }
          break;
        }
        pcVar1 = letter + 1;
        letter = letter + 1;
        iVar3 = pcVar1->letter;
      }
      if (letter->letter == 0) {
        diag_fatal(0x30,(int)*value,g_switch_word);
      }
      cVar2 = value[1];
      value = value + 1;
    } while( true );
  case '$':
    lVar4 = opt_parse_number(value);
    *(long *)row->variable = lVar4;
    return;
  case '&':
    v = *(c1_vector **)row->variable;
    if (dup != 0) {
      value = _strdup(value);
    }
    vector_push(v,value);
    return;
  case '\'':
    if (*(int *)row->variable != 0) {
      pcVar5 = _strdup(row->pattern);
      uVar8 = 0xffffffff;
      pcVar6 = pcVar5;
      do {
        if (uVar8 == 0) break;
        uVar8 = uVar8 - 1;
        cVar2 = *pcVar6;
        pcVar6 = pcVar6 + 1;
      } while (cVar2 != '\0');
      pcVar5[~uVar8 - 2] = '\0';
      diag_fatal(0x2e,pcVar5,*(undefined4 *)row->variable,value);
    }
switchD_1044580d_caseD_22:
    if (dup == 0) {
      *(char **)row->variable = value;
      return;
    }
    pcVar6 = _strdup(value);
    *(char **)row->variable = pcVar6;
    return;
  case '(':
    uVar7 = opt_parse_number_2(value);
    *(ulong *)row->variable = uVar7;
    return;
  }
}

