c2_fe_symbol * __fastcall operand_base_fe_symbol(c2_node *n)

{
  do {
    switch(n->kind) {
    case '\x01':
    case '\x02':
    case '\x03':
      return (c2_fe_symbol *)**(undefined4 **)(n[1].op + 8);
    case '\x04':
      return (c2_fe_symbol *)n[1].op;
    case '\x05':
    case '\x06':
      if (n[2].next != (c2_node *)0x0) {
        return (c2_fe_symbol *)**(undefined4 **)&(n[2].next)->kind;
      }
    default:
      return (c2_fe_symbol *)0x0;
    case '\x0e':
    case '\x11':
      n = *(c2_node **)&n[1].kind;
      break;
    case '\x17':
      return *(c2_fe_symbol **)n[1].op;
    case '\x1a':
      return *(c2_fe_symbol **)&n[1].kind;
    }
  } while( true );
}

