char conv_function_cast_is_unsafe_parameters
               (c1_type_list *from_params,c1_type_list *to_params,int count,c1_conversion *conv)

{
  char cVar1;
  c1_type **ppcVar2;
  c1_type **ppcVar3;
  
  ppcVar2 = to_params->types;
  ppcVar3 = from_params->types;
  if (count < 1) {
    return '\0';
  }
  do {
    cVar1 = conv_function_cast_is_unsafe(conv,*ppcVar3,*ppcVar2,'\x01');
    if (cVar1 != '\0') {
      return '\x01';
    }
    ppcVar3 = ppcVar3 + 1;
    ppcVar2 = ppcVar2 + 1;
    count = count + -1;
  } while (0 < count);
  return '\0';
}

