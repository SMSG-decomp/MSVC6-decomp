void __fastcall option_store_value(c2_option_row *row,char *value,int copy)

{
  c2_letter_option_row *pcVar1;
  int iVar2;
  c2_letter_option_row *pcVar3;
  char cVar4;
  long lVar5;
  char *pcVar6;
  char *pcVar7;
  uint uVar8;
  c2_letter_option_row *pcVar9;
  
  switch(row->kind) {
  case '\x01':
    *(row->u04).flag = 1;
    break;
  default:
    ice_fatal("E:\\8168\\vc98\\p2\\src\\Common\\getflags.c",0xdd);
  case '\x05':
    *(row->u04).flag = 0;
    return;
  case '#':
    cVar4 = *value;
    if (cVar4 != '\0') {
      pcVar3 = (row->u04).letters;
      do {
        iVar2 = pcVar3->letter;
        pcVar9 = pcVar3;
        while (iVar2 != 0) {
          if (cVar4 == (char)pcVar9->letter) {
            iVar2 = pcVar9->kind;
            if (iVar2 == 1) {
              *pcVar9->variable = 1;
            }
            else if (iVar2 == 5) {
              *pcVar9->variable = 0;
            }
            else {
              if (iVar2 != 0x24) {
                ice_fatal("E:\\8168\\vc98\\p2\\src\\Common\\getflags.c",0xd3);
              }
              lVar5 = option_parse_integer(value);
              *pcVar9->variable = lVar5;
              cVar4 = *value;
              while (('/' < cVar4 && (cVar4 < ':'))) {
                pcVar7 = value + 1;
                value = value + 1;
                cVar4 = *pcVar7;
              }
              value = value + -1;
            }
            break;
          }
          pcVar1 = pcVar9 + 1;
          pcVar9 = pcVar9 + 1;
          iVar2 = pcVar1->letter;
        }
        if (pcVar9->letter == 0) {
          fatal_error(0x30,(int)*value,g_option_current_argument);
        }
        cVar4 = value[1];
        value = value + 1;
        if (cVar4 == '\0') {
          return;
        }
      } while( true );
    }
    break;
  case '$':
    lVar5 = option_parse_integer(value);
    *(row->u04).number = lVar5;
    return;
  case '&':
    pcVar3 = (row->u04).letters;
    iVar2 = pcVar3->letter;
    if (iVar2 < 1) {
      fatal_error(0x5e,row->pattern,value);
    }
    if (copy != 0) {
      pcVar7 = _strdup(value);
      pcVar3->letter = iVar2 + -1;
      (&pcVar3->letter)[iVar2] = (int32_t)pcVar7;
      return;
    }
    pcVar3->letter = iVar2 + -1;
    (&pcVar3->letter)[iVar2] = (int32_t)value;
    return;
  case '\'':
    iVar2 = *(row->u04).flag;
    if (iVar2 != 0) {
      pcVar6 = _strdup(row->pattern);
      uVar8 = 0xffffffff;
      pcVar7 = pcVar6;
      do {
        if (uVar8 == 0) break;
        uVar8 = uVar8 - 1;
        cVar4 = *pcVar7;
        pcVar7 = pcVar7 + 1;
      } while (cVar4 != '\0');
      pcVar6[~uVar8 - 2] = '\0';
      fatal_error(0x5d,pcVar6,iVar2,value);
    }
  case '\"':
    if (copy == 0) {
      *(row->u04).text = value;
      return;
    }
    pcVar7 = _strdup(value);
    *(row->u04).text = pcVar7;
    return;
  }
  return;
}

