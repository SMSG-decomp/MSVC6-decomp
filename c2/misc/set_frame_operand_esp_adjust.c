void __fastcall set_frame_operand_esp_adjust(c2_operand *operands,int esp_depth)

{
  int iVar1;
  c2_symbol *obj;
  
  do {
    if (operands == (c2_operand *)0x0) {
      return;
    }
    if (operands->op == 0x14a) {
      obj = operands->sym;
LAB_1073efc3:
      if (((g_esp_adjust_params == 0) || (obj->cls != '\x05')) &&
         ((g_esp_adjust_locals == 0 || (obj->cls == '\x05')))) {
        operands->rank = 0;
      }
      else {
        iVar1 = frame_object_base_adjust(obj);
        operands->rank = iVar1 + esp_depth;
      }
    }
    else if (operands->op == 0x14e) {
      obj = operands->base_sym;
      goto LAB_1073efc3;
    }
    operands = operands->next;
  } while( true );
}

