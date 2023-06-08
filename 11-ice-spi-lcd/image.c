/*
 * image.c
 *
 *  Created on: Sep 11, 2020
 *      Author: Joe Krachey
 */

/*
**  Image data for wisconsin
*/

#include "image.h"

const uint8_t wisconsinBitmaps[] =
{
    0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //                           #
    0x00, 0x00, 0x00, 0x22, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //                           #   #
    0x00, 0x00, 0x00, 0x1A, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //                            ## #
    0x00, 0x00, 0x00, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //                         ##
    0x00, 0x00, 0x0F, 0xC8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //                     ######  #
    0x00, 0x00, 0x3F, 0x90, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //                   #######  #
    0x00, 0x3F, 0xFF, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //           ###############
    0x00, 0xFF, 0xFF, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //         #################
    0x00, 0xFF, 0xFF, 0xFC, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //         ######################
    0x00, 0xFF, 0xFF, 0xFF, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, //         #########################
    0x00, 0xFF, 0xFF, 0xFF, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, //         ##########################
    0x00, 0xFF, 0xFF, 0xFF, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x00, //         ###########################
    0x00, 0xFF, 0xFF, 0xFF, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x00, //         ###########################
    0x00, 0xFF, 0xFF, 0xFF, 0xF8, 0x00, 0x00, 0x00, 0x00, 0x00, //         #############################
    0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, //         ################################
    0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xF8, 0x00, 0x00, 0x00, 0x00, //         #####################################
    0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0x00, 0x00, 0x00, 0x00, //         #######################################
    0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x80, 0x00, 0x00, 0x00, //         #########################################
    0x03, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFC, 0x00, 0x00, 0x00, //       ################################################
    0x0F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xC0, 0x00, 0x00, //     ######################################################
    0x1F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xF0, 0x00, 0x00, //    #########################################################
    0x3F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xF0, 0x00, 0x00, //   ##########################################################
    0x7F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xF8, 0x00, 0x00, //  ############################################################
    0x7F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFC, 0x00, 0x00, //  #############################################################
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0x00, 0x00, // ###############################################################
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, // ################################################################
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0x00, 0x00, // ###############################################################
    0x7F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0x00, 0x00, //  ##############################################################
    0x3F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0x00, 0x40, //   #############################################################          #
    0x1F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0x00, 0x60, //    ############################################################          ##
    0x1F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x80, 0x00, //    ##############################################################
    0x3F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x81, 0x80, //   ###############################################################      ##
    0x3F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x09, 0x80, //   ##############################################################    #  ##
    0x3F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x83, 0x80, //   ###############################################################     ###
    0x3F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x87, 0x00, //   ###############################################################    ###
    0x3F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x87, 0x00, //   ###############################################################    ###
    0x3F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x0E, 0x00, //   ##############################################################    ###
    0x3F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0x0E, 0x00, //   #############################################################     ###
    0x3F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFC, 0x0C, 0x00, //   ############################################################      ##
    0x3F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFC, 0x78, 0x00, //   ############################################################   ####
    0x3F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xF8, 0xF8, 0x00, //   ###########################################################   #####
    0x3F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xF8, 0xF8, 0x00, //   ###########################################################   #####
    0x1F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xF9, 0xF0, 0x00, //    ##########################################################  #####
    0x0F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xF0, 0x00, //     ################################################################
    0x03, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xE0, 0x00, //       #############################################################
    0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xE0, 0x00, //         ###########################################################
    0x00, 0x7F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xC0, 0x00, //          #########################################################
    0x00, 0x1F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xC0, 0x00, //            #######################################################
    0x00, 0x0F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xE0, 0x00, //             #######################################################
    0x00, 0x0F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xE0, 0x00, //             #######################################################
    0x00, 0x07, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xE0, 0x00, //              ######################################################
    0x00, 0x03, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xC0, 0x00, //               ####################################################
    0x00, 0x03, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x80, 0x00, //               ###################################################
    0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, //                 ################################################
    0x00, 0x00, 0x1F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, //                    #############################################
    0x00, 0x00, 0x0F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, //                     ############################################
    0x00, 0x00, 0x0F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x80, 0x00, //                     #############################################
    0x00, 0x00, 0x0F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x80, 0x00, //                     #############################################
    0x00, 0x00, 0x07, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, //                      ###########################################
    0x00, 0x00, 0x07, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, //                      ###########################################
    0x00, 0x00, 0x07, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, //                      ###########################################
    0x00, 0x00, 0x07, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0x00, 0x00, //                      ##########################################
    0x00, 0x00, 0x07, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0x00, 0x00, //                      ##########################################
    0x00, 0x00, 0x07, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0x00, 0x00, //                      ##########################################
    0x00, 0x00, 0x07, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0x00, 0x00, //                      ##########################################
    0x00, 0x00, 0x03, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0x00, 0x00, //                       #########################################
    0x00, 0x00, 0x03, 0xFF, 0xFF, 0xFF, 0xFF, 0xFC, 0x00, 0x00, //                       ########################################
    0x00, 0x00, 0x03, 0xFF, 0xFF, 0xFF, 0xFF, 0xFC, 0x00, 0x00, //                       ########################################
    0x00, 0x00, 0x03, 0xFF, 0xFF, 0xFF, 0xFF, 0xFC, 0x00, 0x00, //                       ########################################
    0x00, 0x00, 0x03, 0xFF, 0xFF, 0xFF, 0xFF, 0xFC, 0x00, 0x00, //                       ########################################
    0x00, 0x00, 0x03, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0x00, 0x00, //                       #########################################
    0x00, 0x00, 0x03, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0x00, 0x00, //                       #########################################
    0x00, 0x00, 0x03, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0x00, 0x00, //                       #########################################
    0x00, 0x00, 0x03, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0x00, 0x00, //                       #########################################
    0x00, 0x00, 0x03, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0x00, 0x00, //                       #########################################
    0x00, 0x00, 0x01, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0x00, 0x00, //                        ########################################
    0x00, 0x00, 0x00, 0x7F, 0xFF, 0xFF, 0xFF, 0xFE, 0x00, 0x00, //                          ######################################
    0x00, 0x00, 0x00, 0x1F, 0xFF, 0xFF, 0xFF, 0xFE, 0x00, 0x00, //                            ####################################
    0x00, 0x00, 0x00, 0x1F, 0xFF, 0xFF, 0xFF, 0xFE, 0x00, 0x00, //                            ####################################
    0x00, 0x00, 0x00, 0x00, 0x07, 0xFF, 0xFF, 0xFE, 0x00, 0x00, //                                      ##########################
};

/* Bitmap sizes for wisconsin */
const uint8_t wisconsinWidthPixels = 75;
const uint8_t wisconsinHeightPixels = 80;


