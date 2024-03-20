#ifndef _tcxxx_model_h
#define _tcxxx_model_h

typedef enum
{
    ARM_SIGMOID = 0,
                /**< Sigmoid activation function */
    ARM_TANH = 1,
             /**< Tanh activation function */
} arm_nn_activation_type;


void arm_relu_q15(signed short int * data, unsigned long int size);
void aia_relu8_q15(signed short int* data, unsigned long int size, unsigned long int shfIn);
void aia_nn_activations_direct_q15(signed short int* data, int size, int int_width, arm_nn_activation_type type, int quantBits);
char arm_fully_connected_q15(const signed short int * pV,
                        const signed short int * pM,
                        const unsigned short int dim_vec,
                        const unsigned short int num_of_rows,
                        const unsigned short int bias_shift,
                        const unsigned short int out_shift,
                        const signed short int * bias,
                        signed short int * pOut,
                        signed short int * vec_buffer);


#endif
