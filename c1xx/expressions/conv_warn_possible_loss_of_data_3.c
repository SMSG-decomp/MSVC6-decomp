void __thiscall conv_warn_possible_loss_of_data_3(void *this,c1_node *node)

{
  char cVar1;
  
  cVar1 = conv_constant_warnings_enabled(this);
  if (cVar1 != '\0') {
    diag_warning(2,0xf4,(uint)*(byte *)this,*(undefined4 *)((int)this + 8),
                 *(undefined4 *)((int)this + 0xc));
  }
  conv_apply_standard_conversion(this,node);
  return;
}

