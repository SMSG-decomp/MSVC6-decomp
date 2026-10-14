void __cdecl opt_set_switch_value(getflags_row *row,char *value,int dup)

{
  char cVar1;
  fe_vector *v;
  int iVar2;
  long lVar3;
  getflags_letter_row *letter;
  char *pcVar4;
  char *pcVar5;
  ulong uVar6;
  uint uVar7;
  getflags_letter_row *next_letter;
  
  switch(row->kind) {
  case '\x01':
    *(row->variable).flag = '\x01';
    return;
  default:
    return;
  case '\x05':
    *(row->variable).flag = '\0';
    return;
  case '\"':
    goto switchD_106130a5_caseD_22;
  case '#':
    cVar1 = *value;
    do {
      if (cVar1 == '\0') {
        return;
      }
      letter = (row->variable).letters;
      iVar2 = letter->letter;
      while (iVar2 != 0) {
        if (cVar1 == (char)letter->letter) {
          if (letter->kind == 1) {
            *letter->flag = '\x01';
          }
          else if (letter->kind == 5) {
            *letter->flag = '\0';
          }
          break;
        }
        next_letter = letter + 1;
        letter = letter + 1;
        iVar2 = next_letter->letter;
      }
      if (letter->letter == 0) {
        diag_fatal(0x30,(int)*value,g_switch_word);
      }
      cVar1 = value[1];
      value = value + 1;
    } while( true );
  case '$':
    lVar3 = opt_parse_number((byte *)value);
    *(row->variable).number = lVar3;
    return;
  case '&':
    v = *(row->variable).list;
    if (dup != 0) {
      value = _strdup(value);
    }
    vector_push(v,value);
    return;
  case '\'':
    if (*(row->variable).text != (char *)0x0) {
      pcVar4 = _strdup(row->pattern);
      uVar7 = 0xffffffff;
      pcVar5 = pcVar4;
      do {
        if (uVar7 == 0) break;
        uVar7 = uVar7 - 1;
        cVar1 = *pcVar5;
        pcVar5 = pcVar5 + 1;
      } while (cVar1 != '\0');
      pcVar4[~uVar7 - 2] = '\0';
      diag_fatal(0x2e,pcVar4,*(row->variable).text,value);
    }
switchD_106130a5_caseD_22:
    if (dup == 0) {
      *(row->variable).text = value;
      return;
    }
    pcVar5 = _strdup(value);
    *(row->variable).text = pcVar5;
    return;
  case '(':
    uVar6 = opt_parse_number_2(value);
    ((row->variable).letters)->letter = uVar6;
    return;
  }
}

